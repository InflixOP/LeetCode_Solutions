class Bank {
private:
   vector<long long> balance;
public:
    Bank(vector<long long>& balance) {
          this->balance = balance;

    }
    bool successful(int account ){
        return account>= 1 && account <=balance.size();

        
    }

    
    bool transfer(int account1, int account2, long long money) {
        if (successful(account1) && successful(account2) && balance[account1 - 1] >= money) {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    
    bool deposit(int account, long long money) {
       if(successful(account)){
        balance[account-1]+=money;
        return true;
       }
       return false;
       }
    bool withdraw(int account, long long money) {
         if (successful(account) && balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};


/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */