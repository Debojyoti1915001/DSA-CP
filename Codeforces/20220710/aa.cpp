func (h *MessengerHandlerImpl) SendMessage(c *gin.Context) {
	lh := logutil.LoggerHelper(c, h.logger, "SendMessage")
	// Default Values for the Request

	request := apiModel.Request{
		ID:        uuid.New().String(),
		Language:  "en",
		TargetApp: headers.PatientApp,
	}
	m := `{
		"$schema": "http://json-schema.org/draft-04/schema#",
		"type": "object",
		"properties": {
		  "lookup_id": {
			"type": "string"
		  },
		  "template_id": {
			"type": "string"
		  },
		  "to": {
			"type": "object",
			"properties": {
			  "user_id": {
				"type": "string"
			  }
			}
		  },
		  "channels": {
			"type": "array",
			"items": [
			  {
				"type": "string"
			  }
			]
		  },
		  "components": {
			"type": "array",
			"items": [
			  {
				"type": "object",
				"properties": {
				  "type": {
					"type": "string"
				  },
				  "parameters": {
					"type": "array",
					"items": [
					  {
						"type": "object",
						"properties": {
						  "type": {
							"type": "string"
						  },
						  "text": {
							"type": "string"
						  }
						}
					  },
					  {
						"type": "object",
						"properties": {
						  "type": {
							"type": "string"
						  },
						  "branch": {
							"type": "string"
						  }
						}
					  },
					  {
						"type": "object",
						"properties": {
						  "type": {
							"type": "string"
						  },
						  "text": {
							"type": "string"
						  }
						}
					  }
					]
				  }
				}
			  },
			  {
				"type": "object",
				"properties": {
				  "type": {
					"type": "string"
				  },
				  "parameters": {
					"type": "array",
					"items": [
					  {
						"type": "object",
						"properties": {
						  "type": {
							"type": "string"
						  },
						  "document": {
							"type": "object",
							"properties": {
							  "caption": {
								"type": "string"
							  },
							  "link": {
								"type": "string"
							  },
							  "filename": {
								"type": "string"
							  }
							}
						  }
						}
					  }
					]
				  }
				}
			  }
			]
		  },
		  "language": {
			"type": "string"
		  },
		  "target_app": {
			"type": "string"
		  },
		  "branch": {
			"type": "array",
			"items": [
			  {
				"type": "object",
				"properties": {
				  "key": {
					"type": "string"
				  },
				  "data": {
					"type": "object",
					"properties": {
					  "pid": {
						"type": "string"
					  },
					  "oid": {
						"type": "string"
					  },
					  "params": {
						"type": "object",
						"properties": {
						  "params": {
							"type": "object",
							"properties": {
							  "saId": {
								"type": "string"
							  }
							}
						  }
						}
					  }
					}
				  }
				},
				"required": [
				  "key",
				  "data"
				]
			  }
			]
		  }
		},
		"required": [
		  "template_id",
		  "to",
		  "channels"
		]
	  }`

	if err := c.ShouldBindJSON(&request); err != nil {
		lh(zap.ErrorLevel, zap.String("ctx", "SendMessageHandler"), zap.Error(err))
		c.JSON(http.StatusBadRequest, gin.H{"error parsing json": err.Error()})
		return
	}

	if request.ID == "" {
		request.ID = uuid.New().String()
	}

	sqsConf, err := h.service.SQSQueue(c, request.TemplateID)
	if err != nil {
		lh(zap.ErrorLevel, zap.String("ctx", "SQSQueueConf"), zap.Error(err), zap.Any("req", request))
		c.JSON(http.StatusBadRequest, gin.H{"error parsing json": err.Error()})
		return
	}
	lh(zap.InfoLevel, zap.Any("req", request))
	schemaLoader := gojsonschema.NewStringLoader(m)
	documentLoader := gojsonschema.NewGoLoader(request)

	result, err := gojsonschema.Validate(schemaLoader, documentLoader)
	if err != nil {
		lh(zap.ErrorLevel, zap.Any("ctx", "check"), zap.Error(err))
		return
	}
	if !result.Valid() {
		lh(zap.ErrorLevel, zap.Any("ctx", result.Valid()), zap.Error(err))
		return
	}
	r, err := h.service.QueueMessage(c, &request, sqsConf.MainQueue, request.Delay)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"Couldn't push to queue": err.Error()})
		return
	}

	lh(zap.DebugLevel, zap.String("ctx", "Request"), zap.String("ip", c.ClientIP()), zap.Any("msg", request))
	c.JSON(http.StatusOK, gin.H{"status": "queued", "sqs_receipt": r, "id": request.ID})
}
