#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
vector <string> reshala(vector <string> (x), int colvo)
{

    int y, z;

    for (int c = 0; c < colvo; c++)
    {

        int be = 0, en = x.size();

        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == "(")
            {
                be = i;
            }
            if (x[i] == ")")
            {
                en = i;

                x.erase(x.begin() + en);
                x.erase(x.begin() + be);
                en = en - 1;
                break;
            }
        }
        for (int i = be; i < en; i++)
        {
            if (x[i] == "*" or x[i] == "/")
            {
                if (x[i] == "*")
                {
                    istringstream(x[i - 1]) >> y;
                    istringstream(x[i + 1]) >> z;
                    x[i - 1] = to_string(y * z);
                    x.erase(x.begin() + i);
                    x.erase(x.begin() + i);
                    en = en - 2;
                }
                else
                {
                    istringstream(x[i - 1]) >> y;
                    istringstream(x[i + 1]) >> z;
                    x[i - 1] = to_string(y / z);
                    x.erase(x.begin() + i);
                    x.erase(x.begin() + i);
                    en = en - 2;
                }
            }
        }

        for (int i = be; i < en; i++)
        {
            if (x[i] == "+" or x[i] == "-")
            {
                if (x[i] == "+")
                {
                    istringstream(x[i - 1]) >> y;
                    istringstream(x[i + 1]) >> z;
                    x[i - 1] = to_string(y + z);
                    x.erase(x.begin() + i);
                    x.erase(x.begin() + i);
                    en = en - 2;
                }
                else
                {
                    istringstream(x[i - 1]) >> y;
                    istringstream(x[i + 1]) >> z;
                    x[i - 1] = to_string(y - z);
                    x.erase(x.begin() + i);
                    x.erase(x.begin() + i);
                    en = en - 2;
                }
            }
        }
    }
    return x;
}
int main()
{

    system("chcp 1251");

    while (true)
    {

        cout << "Вводите по элементы через пробел (пример: 10 * ( 10 + 10 ) = ), а как закончите введите '='" << endl;
        vector <string> x;

        int skob = 0, colvo = 0;

        bool err = false;

        string b;

        while (true)
        {
            cin >> b;
            bool zn = false, chi = false;

            if (b[0] == '=')
            {
                break;
            }

            for (int i = 0; i < b.size(); i++)
            {

                if (b.size() > 1 and b[0] == '-')
                    chi = true;
                if ((b[i] == '*' or b[i] == '/' or b[i] == '+' or b[i] == '(' or b[i] == ')') and b.size() == 1)
                    zn = true;
                if (isdigit(b[i]))
                    chi = true;
                if (chi == zn)
                    err = true;


                if (b[0] == '(' and (b.size() == 1))
                {
                    colvo++;
                    skob++;
                }

                if (b[0] == ')' and (b.size() == 1))
                {
                    skob--;
                }

            }

            x.push_back(b);

            if (x.size() == 1 and (x[0] == "*" or x[0] == "/" or x[0] == "+" or x[0] == "-" or x[0] == ")"))
            {
                err = true;
            }

        }

        if (!(skob == 0))
        {
            err = true;
        }

        for (int i = 1; i < x.size(); i++)
        {
            if ((x[i] == "*" or x[i] == "/" or x[i] == "+" or x[i] == "-" or x[i] == ")") and (x[i - 1] == "*" or x[i - 1] == "/" or x[i - 1] == "+" or x[i - 1] == "-" or x[i - 1] == ")"))
                err = true;

            if (isdigit(x[i][x[i].size() - 1]) and isdigit(x[i - 1][x[i - 1].size() - 1]))
                err = true;
        }

        if (x.size() < 3)
        {
            err = true;
        }

        if (!err)
        {
            if (x[x.size() - 1] == "*" or x[x.size() - 1] == "/" or x[x.size() - 1] == "+" or x[x.size() - 1] == "-" or x[x.size() - 1] == "(")
            {

                err = true;

            }
        }

        if (!err)
        {

            x = reshala(x, colvo + 2);

            cout << x[0];

            x.clear();

        }
        else
        {
            x.clear();
            cout << "Ошибка вводa";
        }

        cout << endl;

    }

}