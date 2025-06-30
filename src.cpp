#include <iostream>
#include <string>

using namespace std;

int main() {
    string ok;
    bool is_num, num_1 = 0;
    char mass[] = {'+', '-', '/', '*'};
    int num = 0, num_2 = 0;
    char operand;
    cout << "Привет, введи пример:\n> ";
    getline(cin, ok);
    ok.append(" ");

    string buffer = "";
    for (char ch : ok) {
        if (ch != ' '){
            if (ch > 47 && ch < 58){
                is_num = true;
                buffer += ch;
            } else {
                is_num = false;
            }

        } else if (!buffer.empty() && ch == ' ') {
            if (is_num){
                if (num_1) {
                    num_2 = stoi(buffer);
                    int temp = 0;
                    for (char c:mass){
                        int a = ok.find(c);
                        if (a != string::npos){
                            switch (c) {
                                case '+': num += num_2; break;
                                case '-': num -= num_2; break;
                                case '*': num *= num_2; break;
                                case '/': num /= num_2;
                                default: break;
                            }
                            cout << num << endl;
                        }
                    }

                } else {
                    num = stoi(buffer);
                    num_1 = !num_1;
                }
            }
            cout << "Токен: " << buffer << endl;

            buffer = "";

        }
    }

    cout << "= " << num << endl;

    return 0;
}
