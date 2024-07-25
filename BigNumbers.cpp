#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif
#ifndef _GLIBCXX_VECTOR
#include <vector>
#endif
#ifndef _GLIBCXX_STRING
#include <string>
#endif
#ifndef _INC_CONIO
#include <conio.h>
#endif

using namespace std;

class BigNumber {
    private:
    vector<char> number;
    bool negative=false;

    void print() {
        if(number.size()==1 && number.at(0)=='0'){
            negative=false;
        }
        if(negative){
            cout<<'-';
        }
        for (char c : number) {
            cout << c;
        }
    }

     void input() {
        number.clear();
        negative = false;
        int i = 0;
        char ch;
        do {
            ch = getch();
            if (ch >= '0' && ch <= '9') {
                cout << ch;
                number.push_back(ch);
            } else if (i == 0 && ch == '-' && !negative) {
                cout<<ch;
                negative = true;
            } else if (ch == 8) { // Backspace key
                if (!number.empty()) {
                    cout<<'\b'<<' '<<'\b';
                    number.pop_back();
                    if (number.empty()) {
                        i = -1;
                    }
                } 
                else if (negative) {
                    cout<<'\b'<<' '<<'\b';
                    negative = false;
                    i = -1;
                }
            }
            i++;
        } while (ch != 13);  // Enter key
    }

    int ctoi(char ch) const {
        if(ch>='0' && ch<='9'){
            return ch - '0';
        }
        throw std::runtime_error("ctoi: character must be in range 0 to 9");
    }

    char itoc(int i) const {
        if(i>=0 && i<=9){
            return '0' + i;
        }
        throw std::runtime_error("itoc: integer must be in range 0 to 9");
    }


public:
    BigNumber() {
        this->negative=false;
    }

    BigNumber(const string& number) {
        this->negative=false;
        this->number.clear();
       
        int k=0;
        for (char i : number) {
            if(i=='-' && k==0){
                this->negative=true;
                k++;
                continue;
            }
            if(i<='9' && i>='0'){
            this->number.push_back(i);
                k++;
            }
            else{
                throw std::runtime_error("BigNumber: number is not valid");
            }
        }

    }

    void operator=(const string &number) {
        this->number.clear();
        this->negative=false;
        int k=0;
        for (char i : number) {
            if(i=='-' && k==0){
                this->negative=true;
                k++;
                continue;
            }
            if(i<='9' && i>='0'){
            this->number.push_back(i);
                k++;
            }
            else{
                throw std::runtime_error("BigNumber: number is not valid");
            }

        }
    }

    bool operator==(BigNumber &num){
        if(this->negative == num.negative){
            return this->number==num.number;
        }
        return false;
    }

    bool operator>=(const BigNumber& num) const {
        if(this->negative!=num.negative){
            return !this->negative;
        }

        if (this->number.size() != num.number.size()) {
            if(this->negative==num.negative && this->negative==true){
                return this->number.size()<num.number.size();
            }
            else if(this->negative==num.negative && this->negative==false){
                return this->number.size() > num.number.size();
            }
            else{
                return !this->negative;
            }
        }
        for (size_t i = 0; i < this->number.size(); ++i) {
            if (this->number[i] != num.number[i]) {
                if(this->negative){
                    // both numbers are negative
                return this->number[i] < num.number[i];
                }else{
                    // both numbers are positive
                    return this->number[i] > num.number[i];
                }
            }
        }
        return true;
    }

    bool operator>(BigNumber& num){
      if(this->negative!=num.negative){
            return !this->negative;
        }

        if (this->number.size() != num.number.size()) {
            if(this->negative==num.negative && this->negative==true){
                return this->number.size()<num.number.size();
            }
            else if(this->negative==num.negative && this->negative==false){
                return this->number.size() > num.number.size();
            }
            else{
                return !this->negative;
            }
        }
        for (size_t i = 0; i < this->number.size(); ++i) {
            if (this->number[i] != num.number[i]) {
                if(this->negative){
                    // both numbers are negative
                return this->number[i] < num.number[i];
                }else{
                    // both numbers are positive
                    return this->number[i] > num.number[i];
                }
            }
        }
        return false;
    }

    bool operator<(BigNumber &n){
        if(*this==n){
            return false;
        }
        return *this>n?false:true;
    }

    
    bool operator<=(BigNumber &n){
        if(*this==n){
            return true;
        }
        return *this>n?false:true;
    }

    BigNumber operator--(){
        BigNumber one=BigNumber("1");
        *this=*this-one;
        return *this;
    }
    
    BigNumber operator--(int){
        BigNumber one=BigNumber("1");
        BigNumber temp;
        temp=*this;
        *this=*this-one;
        return temp;
    }

    
    BigNumber operator++(){
        BigNumber one=BigNumber("1");
        *this=*this+one;
        return *this;
    }

    
    BigNumber operator++(int){
        BigNumber one=BigNumber("1");
        BigNumber temp;
        temp=*this;
        *this=*this+one;
        return temp;
    }

    BigNumber operator+(BigNumber& num) {
        if(this->negative!=num.negative){
            // if both numbers are of different signs
            BigNumber temp;
            if(this->negative){
                this->negative=false;
                temp=num-*this;
                this->negative=true;
            }
            else{
                num.negative=false;
                temp=*this-num;
                num.negative=true;
            }
            return temp;
        }

        int carry = 0, num1 = 0, num2 = 0;
        int num1_size = this->number.size();
        int num2_size = num.number.size();
        int max_size = std::max(num1_size, num2_size);
        BigNumber result;
        result.number.resize(max_size + 1, '0');

        for (int i = max_size - 1; i >= 0; --i) {
            num1 = (num1_size > 0) ? ctoi(this->number[--num1_size]) : 0;
            num2 = (num2_size > 0) ? ctoi(num.number[--num2_size]) : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            result.number[i + 1] = itoc(sum % 10);
        }

        if (carry) {
            result.number[0] = itoc(carry);
        } else {
            result.number.erase(result.number.begin());
        }

        // if both numbers are negative
        if(this->negative==num.negative && this->negative){
            result.negative=true;
        }
        return result;
    }

    BigNumber operator-(BigNumber& num){
        
        if(this->negative!=num.negative){
            BigNumber temp;
            if(this->negative){
                this->negative=false;
                temp=*this+num;
                temp.negative=true;
                this->negative=true;
            }
            else{
                num.negative=false;
                temp=*this+num;
                num.negative=true;
            }
            return temp;
        }
        else if(this->negative==num.negative && this->negative){
            BigNumber temp;
            num.negative=false;
            this->negative=false;
            temp=num-*this;
            num.negative=true;
            this->negative=true;
            return temp;
        }
        BigNumber a=BigNumber::abs(*this);
        BigNumber b=BigNumber::abs(num);
        

        BigNumber max_num = BigNumber::max(a,b);
        BigNumber min_num = BigNumber::min(a,b);
        

        bool borrow = false;
        int min_size = min_num.number.size();
        int max_size = max_num.number.size();

        BigNumber result;
        result.number.resize(max_size, '0');

        for (int i = 0; i < max_size; ++i) {
            int num1 = ctoi(max_num.number[max_size - 1 - i]);
            int num2 = (min_size - 1 - i >= 0) ? ctoi(min_num.number[min_size - 1 - i]) : 0;

            if (borrow) {
                num1--;
                borrow = false;
            }

            if (num1 < num2) {
                num1 += 10;
                borrow = true;
            }

            result.number[max_size - 1 - i] = itoc(num1 - num2);
        }

        // Remove leading zeros
        while (result.number.size() > 1 && result.number[0] == '0') {
            result.number.erase(result.number.begin());
        }
        
        if(BigNumber::abs(num)==max_num){
            result.negative=true;
        }
        return result;
    }

    BigNumber operator+=(BigNumber &n){
        BigNumber temp;
        temp=n+*this;
        *this=temp;
        return temp;
    }

    
    BigNumber operator-=(BigNumber &n){
        BigNumber temp;
        temp=*this-n;
        *this=temp;
        return temp;
    }

    BigNumber operator*(BigNumber &n){
        BigNumber multiplicand=BigNumber::abs(this->number.size()>n.number.size()?*this:n);
        BigNumber multiplier=BigNumber::abs(multiplicand==*this?n:*this);
        unsigned int multiplier_size=multiplier.number.size();
        unsigned int multiplicand_size=multiplicand.number.size();
        vector<BigNumber> array;

        int num1=0,num2=0,carry=0,product=0;
        BigNumber temp;
        temp.number.resize(multiplicand_size+1,'0');

        for(int i=0;i<multiplier_size;i++){
            num1= ctoi(multiplier.number.at(multiplier_size-1-i));
            for(int j=0;j<multiplicand_size;j++){
                num2=ctoi(multiplicand.number.at(multiplicand_size-1-j));
                product=(num1*num2)+carry;
                carry=product/10;
                temp.number.at(multiplicand_size-j)=itoc(product%10);
            }
            if(carry){
                temp.number.at(0)=itoc(carry);
            }
            else{
                temp.number.at(0)='0';
            }
            carry=0;
            array.push_back(temp);
        }
        BigNumber result;
        unsigned int result_size=multiplicand_size+multiplier_size;
        result.number.resize(result_size,'0');
        int j=0;
        temp.number.clear();
        temp="0";
        temp=array.at(0);
        for(int i=0;i<array.size()-1;i++){
            result.number.at(result_size-i-1)=temp.number.at(temp.number.size()-1);
            temp.number.erase(temp.number.end());
            temp=temp+array.at(i+1);
            j++;
        }
            int k=0;
            for(int i=result_size-j-1;i>=0;i--){
                result.number.at(i)=temp.number.at(multiplicand_size-k);
                k++;
            }


        while(result.number.size()>1 && result.number.at(0)=='0'){
            result.number.erase(result.number.begin());
        }
        return result;
    }

    static BigNumber abs(BigNumber &n){
        if(n.negative){
        BigNumber temp;
        n.negative=false;
        temp=n;
        n.negative=true;
        return temp;
        }
        return n;
    }

    static BigNumber max(BigNumber& n1, BigNumber& n2) {
        return n1>n2? n1 : n2;
    }

    static BigNumber min(BigNumber &n1,BigNumber &n2){
        return n1>n2?n2:n1;
    }

    friend ostream& operator<<(ostream&, BigNumber);
    friend istream& operator>>(istream&, BigNumber&);

};

ostream& operator<<(ostream& dout, BigNumber n) {
    n.print();
    return dout;
}

istream& operator>>(istream& din, BigNumber& n) {
    n.input();
    return din;
}

int main() {
    BigNumber n1("2385"), n2("333");
    cout<<"Enter a number: ";
    cin>>n1;
    cout<<"\nEnter a number: ";
    cin>>n2;
    
    cout<<endl<<"Result is :"<<n1*n2;
    return 0;
}
