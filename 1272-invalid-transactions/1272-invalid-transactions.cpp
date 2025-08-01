class transaction {
public:
    int time;
    int amount;
    string city;
    string whole_transaction_string;
    bool marked;

    transaction(int t, int a, string city, string s) {
        this->time = t;
        this->amount = a;
        this->city = city;
        this->whole_transaction_string = s;
        this->marked = false;
    }
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<transaction*>> mp;
        for(string& s : transactions) {
            istringstream ss(s);
            string token = "";

            getline(ss, token, ',');
            string name = token;
            getline(ss, token, ',');
            int time = stoi(token);
            getline(ss, token, ',');
            int amt = stoi(token);
            getline(ss, token, ',');
            string city = token;

            transaction *t = new transaction(time, amt, city, s);
            mp[name].push_back(t);

        }

        for(auto& [name, trans] : mp) {
            sort(trans.begin(), trans.end(), [](const transaction* a, const transaction* b) {
                return a->time < b->time;
            });
        }

        vector<string> result;
        for(auto& [name, trans] : mp) {
            for(int i = 0; i<trans.size(); i++) {
                if(trans[i]->amount > 1000) {
                    result.push_back(trans[i]->whole_transaction_string);
                    trans[i]->marked = true;
                }

                if(i > 0 && trans[i]->time - trans[i-1]->time <= 60) {
                    int r = i-1;
                    while(r >= 0 && trans[i]->time - trans[r]->time <= 60) {
                        if(trans[r]->city != trans[i]->city) {
                            if(trans[r]->marked == false) {
                                result.push_back(trans[r]->whole_transaction_string);
                                trans[r]->marked = true;
                            }
                            if(trans[i]->marked == false) {
                                result.push_back(trans[i]->whole_transaction_string);
                                trans[i]->marked = true;
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