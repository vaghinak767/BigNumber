#include <iostream>
#include <vector>
class Res
{
private:
    std::vector<short> result;
    bool sign;

public:
    Res(std::vector<short> res, bool s) : result{res}, sign{s} {}
    const std::vector<short> get() const
    {
        return result;
    }
    bool getSign() const
    {
        return sign;
    }
    Res &foo()
    {
        this->sign ^= 1;
        return *this;
    }
};
Res Big_number_add(std::vector<short>, std::vector<short>, bool, bool);
const Res Big_number_subtraction(std::vector<short>, std::vector<short>, bool, bool);
std::ostream &operator<<(std::ostream &, const std::vector<short> &);
std::ostream &operator<<(std::ostream &out, const Res &ob)
{
    if (ob.getSign())
    {
        out << "-";
    }
    return (out << (ob.get()));
}
std::ostream &operator<<(std::ostream &out, const std::vector<short> &ob)
{
    int n = ob.size(), i = 0;
    while (i < n && !ob[i])
    {
        ++i;
    }
    if (i == n)
        return out << 0;
    while (i != n)
    {
        out << ob[i];
        ++i;
    }
    return out;
}
void Big_number_division(int *Number1, int *Number2, int *result, int n)
{
    int pad = 0, count = 9;
    for (int i = 0; i < n; ++i)
    {
        do
        {
            int z = 0;
            if (Number2[i] == 0 && Number1[i] == 0)
            {
                continue;
            }
            while (Number2[i + pad] == 0)
            {
                ++pad;
            }
            int count = 0, tiv = Number1[i];
            if (i + pad == n)
            {
                break;
            }
            while (Number1[i] >= Number2[i + pad] && Number1[i] != 0 && Number2[i + pad])
            {
            }
        } while (0); //------------------------------------------
    }
}
Res Big_number_add(std::vector<short> Number1, std::vector<short> Number2, bool s1, bool s2)
{
    if (s1 && !s2)
    {
        return Big_number_subtraction(Number2, Number1, 0, 0);
    }
    if (s2 && !s1)
    {
        return Big_number_subtraction(Number1, Number2, 0, 0);
    }
    bool flag = false;
    if (s1 && s2)
    {
        flag = true;
    }
    int n1 = Number1.size();
    int n2 = Number2.size();
    int min = n1 < n2 ? n1 : n2;
    int max = n1 > n2 ? n1 : n2;
    std::vector<short> result(max + 1, 0);
    int i = 0;
    for (; i < min; ++i)
    {
        result[max - i] += (Number1[n1 - i - 1] + Number2[n2 - 1 - i]);
        if (result[max - i] >= 10)
        {
            result[max - i] = result[max - i] % 10;
            ++result[max - i - 1];
        }
    }
    while (i < n1)
    {
        result[max - i] += Number1[n1 - i - 1];
        if (result[max - i] >= 10)
        {
            result[max - i] = result[max - i] % 10;
            ++result[max - i - 1];
        }
        ++i;
    }
    while (i < n2)
    {
        result[max - i] += Number2[n2 - i - 1];
        if (result[max - i] >= 10)
        {
            result[max - i] = result[max - i] % 10;
            ++result[max - i - 1];
        }
        ++i;
    }
    return Res(result, flag);
}
const Res Big_number_multipy(std::vector<short> Number1, std::vector<short> Number2, bool s1, bool s2)
{
    int n1 = Number1.size();
    int n2 = Number2.size();
    int max = n1 > n2 ? n1 : n2;
    if (!Number1.size() || !Number2.size())
    {
        return Res(std::vector<short>(0), 0);
    }
    int a = 0;
    int m = 2 * max;
    std::vector<short> result(m, 0);
    for (int c = n2 - 1; c >= 0; --c)
    {
        for (int j = m - 1, l = n1 - 1; l >= 0; --j, --l)
        {
            for (int i = 0; i < Number2[c]; ++i)
            {
                result[j] += Number1[l];
            }
            if (result[j] >= 10)
            {
                result[j - 1] += (result[j] / 10);
                result[j] %= 10;
            }
        }
        --m;
    }
    return Res(result, s1 ^ s2);
}
const Res Big_number_subtraction(std::vector<short> Number1, std::vector<short> Number2, bool s1, bool s2)
{
    if (s1 && !s2)
    {
        return (Big_number_add(Number2, Number1, 0, 0).foo());
    }
    if (s2 && !s1)
    {
        return Big_number_add(Number1, Number2, 0, 0);
    }
    if (s1 && s2)
    {
        return Big_number_subtraction(Number2, Number1, 0, 0);
    }
    int n1 = Number1.size();
    int n2 = Number2.size();
    int min = n1 < n2 ? n1 : n2;
    int max = n1 > n2 ? n1 : n2;
    std::vector<short> result(max, 0);
    if (n1 < n2)
    {
        int qayl = n2 - n1;
        int a = 0;
        for (int i = n2 - 1; i >= qayl; --i)
        {
            a = Number2[i];
            if (a < Number1[i - n2 + n1])
            {
                a += 10;
                --Number2[i - 1];
            }
            a -= Number1[n1 - n2 + i];
            result[i] = a;
        }
        for (int i = qayl - 1; i >= 0; --i)
        {
            result[i] = Number2[i];
        }
        return Res(result, 1);
    }
    else if (n1 > n2)
    {
        int qayl = n1 - n2;
        int a = 0;
        for (int i = n1 - 1; i >= qayl; --i)
        {
            a = Number1[i];
            if (a < Number2[i - n1 + n2])
            {
                a += 10;
                --Number1[i - 1];
            }
            a -= Number2[n2 - n1 + i];
            result[i] = a;
        }
        for (int i = qayl - 1; i >= 0; --i)
        {
            result[i] = Number1[i];
        }
        return Res(result, 0);
    }
    else
    {
        for (int i = 0; i < n1; ++i)
        {
            if (Number1[i] < Number2[i])
            {
                int a = 0;
                for (int i = n1 - 1; i >= 0; --i)
                {
                    a = Number2[i];
                    if (a < Number1[i])
                    {
                        a += 10;
                        --Number2[i - 1];
                    }
                    a -= Number1[i];
                    result[i] = a;
                }
                return Res(result, 1);
            }
            else if (Number1[i] > Number2[i])
            {
                int a = 0;
                for (int i = n1 - 1; i >= 0; --i)
                {
                    a = Number1[i];
                    if (a < Number2[i])
                    {
                        a += 10;
                        --Number1[i - 1];
                    }
                    a -= Number2[i];
                    result[i] = a;
                }
                return Res(result, 0);
            }
        }
    }
    return Res(std::vector<short>(0), 0);
}
void print(std::vector<short> n1, std::vector<short> n2, bool s1, bool s2, char c)
{
    if (s1)
        std::cout << "-";
    std::cout << n1 << " " << c << " ";
    if (s2)
        std::cout << "(-";
    std::cout << n2;
    if (s2)
        std::cout << ")";
    std::cout << " = ";
}
int main()
{
    std::cout << "Please enter the first number ";
    std::vector<short> Number1, Number2;
    std::string tmp;
    std::cin >> tmp;
    int n = tmp.size();
    int i = 0;
    bool sign1 = false;
    bool flag = true;
    for (; i < n; ++i)
    {
        if (tmp[0] == '-')
        {
            ++i;
            sign1 = true;
        }
        if (n == 1 && tmp[0] == '0')
            break;
        if (flag && i < n && tmp[i] == '0')
        {
            std::cout << "Pleas enter correct number, is must include '-' or nothing at begining and only numbers starting with 1-9 digits, then 0-9 digits ";
            tmp.clear();
            std::cin >> tmp;
            n = tmp.size();
            i = -1;
            continue;
        }
        if ('0' > tmp[i] || tmp[i] > '9')
        {
            std::cout << "Pleas enter correct number, is must include '-' or nothing at begining and only numbers starting with 1-9 digits, then 0-9 digits ";
            Number1.clear();
            tmp.clear();
            i = -1;
            std::cin >> tmp;
            flag = true;
            n = tmp.size();
            continue;
        }
        flag = false;
        Number1.push_back(tmp[i] - 48);
    }
    std::cout << "Please enter the second number ";
    std::cin >> tmp;
    n = tmp.size();
    i = 0;
    bool sign2 = false;
    for (; i < n; ++i)
    {
        if (tmp[0] == '-')
        {
            ++i;
            sign2 = true;
        }
        if (n == 1 && tmp[0] == '0')
            break;
        if (flag && i < n && tmp[i] == '0')
        {
            std::cout << "Pleas enter correct number, is must include '-' or nothing at begining and only numbers starting with 1-9 digits, then 0-9 digits ";
            tmp.clear();
            std::cin >> tmp;
            n = tmp.size();
            i = -1;
            continue;
        }
        if ('0' > tmp[i] || tmp[i] > '9')
        {
            std::cout << "Pleas enter correct number, is must include '-' or nothing at begining and only numbers starting with 1-9 digits, then 0-9 digits ";
            tmp.clear();
            Number2.clear();
            std::cin >> tmp;
            i = -1;
            flag = true;
            n = tmp.size();
            continue;
        }
        flag = false;
        Number2.push_back(tmp[i] - 48);
    }
    tmp.clear();
    print(Number1, Number2, sign1, sign2, '+');
    std::cout << Big_number_add(Number1, Number2, sign1, sign2) << std::endl;
    print(Number1, Number2, sign1, sign2, '-');
    std::cout << Big_number_subtraction(Number1, Number2, sign1, sign2) << std::endl;
    print(Number1, Number2, sign1, sign2, '*');
    std::cout << Big_number_multipy(Number1, Number2, sign1, sign2) << std::endl;
    return 0;
}
