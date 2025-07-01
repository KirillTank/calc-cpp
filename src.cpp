#include <iostream>
#include <string>
#include <type_traits>

using namespace std;
void calc(int* mas, string &str);

template<class T, class U>
void write_mass(T& mas, U arg) {
    for (auto& ok : mas) {
        if constexpr (is_same<remove_extent_t<T>, int>::value) {
            if (ok == 0) {
                ok = arg;
                break;
            }
        }
    }
}

int main() {
    bool is_num = false;

    int mas_num[100] = {0};
    string mas_oper = "";

    string buffer;
    string input;

    cout << "Введи пример (например: 3 + 5 * 2):\n> ";
    getline(cin, input);
    input.append(" ");

    for (char ch : input) {
        if (isdigit(ch)) {
            is_num = true;
            buffer += ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            mas_oper += ch ;
        } else if (ch == ' ') {
            if (!buffer.empty()) {
                if (is_num) {
                    int o = stoi(buffer);
                    write_mass(mas_num, o);

                buffer.clear();
                is_num = false;
                }
            }
        }
    }

    calc(mas_num, mas_oper);
    cout << mas_num[0];

    return 0;
}

void calc(int* mas, string &str) {
    char oper[] = {'*', '/', '-', '+'};

    while (!str.empty()) {
        bool found = false;
        for (char ch : oper) {
            size_t a = str.find(ch);
            if (a != string::npos) {
                found = true;
                switch (ch) {
                    case '*':
                        mas[a] *= mas[a+1];
                        break;
                    case '/':
                        if (mas[a+1] != 0) {
                            mas[a] /= mas[a+1];
                        } else {
                            cout << "Error: division by zero" << endl;
                        }
                        break;
                    case '-':
                        mas[a] -= mas[a+1];
                        break;
                    case '+':
                        mas[a] += mas[a+1];
                        break;
                }
                mas[a+1] = 0;
                str.replace(a, 1, "");
                break; // После обработки одной операции — переходим к следующей итерации while
            }
        }
        if (!found) break;
    }
}
