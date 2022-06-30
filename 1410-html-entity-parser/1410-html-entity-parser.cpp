class Solution {
public:
    string entityParser(string text) {    
    vector<pair<string,char>> encoded[8] = {{}, {}, {}, {}, {{"&gt;", '>'}, {"&lt;", '<'}},
        {{"&amp;", '&'}}, {{"&quot;", '"'}, {"&apos;", '\''}}, {{"&frasl;", '/'}}};
    int st = 0, p = 0;
    for (auto i = 0; i < text.size(); ++i, ++p) {
        text[p] = text[i];
        if (text[p] == '&')
            st = p;
        if (text[p] == ';') { 
            auto sz = p - st + 1;
            if (sz >= 4 && sz <= 7)
                for (auto &[enc, dec] : encoded[sz]) {
                    if (text.compare(st, sz, enc) == 0) {
                        p = st;
                        text[p] = dec;
                        break;
                    }
                }
            st = p + 1;
        }
    }
    text.resize(p);
    return text;
}
};