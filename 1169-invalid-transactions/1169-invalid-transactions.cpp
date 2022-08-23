class transaction {
public:
    int time;
    int amount;
    string city;
    //to store the original string to later push into the result;
    string tran;
    //to mark each transaction if it has been already pushed into result or not to avoid duplication
    bool marked;
    
    transaction (int t, int a, string c, string tr) {
        tran = tr;
        time = t;
        amount = a;
        city = c;
        marked = false;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if(transactions.empty())
            return {};
        unordered_map<string, vector<transaction*>> trans;
        for(string &st : transactions) {
            istringstream ss(st);
            string token = "";
            //split the input string to get the different values and create a transaction object.
            getline(ss, token, ',');
            string name = token;
            getline(ss, token, ',');
            int time = stoi(token);
            getline(ss, token, ',');
            int amount = stoi(token);
            getline(ss, token, ',');
            string city = token;
            
            transaction *t = new transaction(time, amount, city, st);
            trans[name].push_back(t);
        }
        vector<string> result;
        //now validate the transactions per user name
        for(auto &p : trans) {
            //first sort the transactions in ascending order of time for that particular user
            sort(p.second.begin(), p.second.end(), [](const transaction* a, const transaction* b) {
                return a->time < b->time;
            });
            for(int i=0; i<p.second.size(); i++) {
                //if amount > 1000, mark it as invalid and push into the result
                if(p.second[i]->amount > 1000) {
                    result.push_back(p.second[i]->tran);
                    p.second[i]->marked = true;
                }
                //now loop back the transactions for this user until t-60 and check if any invalid transactions are there. If so, mark it and push it into result
                if(i > 0 && p.second[i]->time <= p.second[i-1]->time + 60) {
                    int r = i-1;
                    while(r >= 0 && p.second[r]->time >= p.second[i]->time - 60) {
                        if(p.second[i]->city != p.second[r]->city) {
                            if(!p.second[r]->marked) {
                                result.push_back(p.second[r]->tran);
                                p.second[r]->marked = true;
                            }
                            if(!p.second[i]->marked) {
                                p.second[i]->marked = true;
                                result.push_back(p.second[i]->tran);
                            }
                        }
                        r--;
                    }
                }
            }
        }
        return result;
    }
};