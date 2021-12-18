#include <iostream>
#include <cmath>
#include <clocale>
class Polinom
{

public:
    void koeff1(int n1)
    {
        int k[10] = { 0 };
        std::cout << "enter koeff of monoms:\n";
        for (int i = 0; i <= n1; i++)
            std::cin >> k[i];
        polin1(n1, k);
    }

    void polin1(int n1, int* k)
    {
        int m = n1;
        for (int i = 0; i < n1; i++)
        {
            std::cout << k[i] << "*x^(" << m << ") + ";
            m--;
        }
        std::cout << k[n1];
        int n2;
        std::cout << "\nDegree of the second polinom:\n";
        std::cin >> n2;
        if (n2 > 9) {
            std::cout << "Error! too big degree";
            exit(-1);
        }
        koeff2(n1, n2, k);
    };

    void koeff2(int n1, int n2, int* k)
    {
        int z[10] = { 0 };
        std::cout << "\nenter koeff of monoms\n";
        for (int i = 0; i <= n2; i++)
            std::cin >> z[i];
        polin2(n1, n2, k, z);
    }

    void polin2(int n1, int n2, int* k, int* z)
    {
        int m = n2;
        for (int i = 0; i < n2; i++)
        {
            std::cout << z[i] << "*x^(" << m << ") + ";
            m--;
        }
        std::cout << z[n2];
        sum2(n1, n2, k, z);
    }

    void sum2(int n1, int n2, int* k, int* z) {
        int s1 = n1;
        int s2 = n2;
        int nn[20];
        std::cout << "\nsum of polinoms: \n";
        for (int i = 0; ((i <= n1) || (i <= n2)) & (s1 > 0) & (s2 > 0); i++) {
            if (s1 == s2) {
                nn[i] = k[i] + z[i];
                std::cout << nn[i] << "*x^(" << s1 << ")";
                s1--;
                s2--;
            }
            if (s1 > s1) {
                std::cout << k[i] << "*x^(" << s1 << ")";
                s1--;
            }
            if (s2 > s1) {
                std::cout << z[i] << "*x^(" << s2 << ")";
                s2--;
            }
            std::cout << " + ";
        }
        std::cout << k[n1] + z[n2];
        subtr2(n1, n2, k, z);
    }

    void subtr2(int n1, int n2, int* k, int* z) {
        int s1 = n1;
        int s2 = n2;
        int nn[20];
        std::cout << "\ndifference of polinoms: \n";
        for (int i = 0; ((i <= n1) || (i <= n2)) & (s1 > 0) & (s2 > 0); i++) {
            nn[i] = k[i] - z[i];
            if (s1 == s2) {
                std::cout << nn[i] << "*x^(" << s1 << ")";
                s1--;
                s2--;
            }
            if (s1 > s1) {
                std::cout << nn[i] << "*x^(" << s1 << ")";
                s1--;
            }
            if (s2 > s1) {
                std::cout << nn[i] << "*x^(" << s2 << ")";
                s2--;
            }
            std::cout << " + ";
        }
        std::cout << k[n1] - z[n2];
        multiply2(n1, n2, k, z);
    }

    void multiply2(int n1, int n2, int* k, int* z) {
        int s1 = n1;
        int s2 = n2;
        int nn[20];
        std::cout << "\nmultiply of polinoms: \n";
        for (int i = 0; ((i <= n1) || (i <= n2)) & (s1 > 0) & (s2 > 0); i++) {
            if (s1 == s2) {
                nn[i] = k[i] * z[i];
                std::cout << nn[i] << "*x^(" << s1 * 2 << ")";
                s1--;
                s2--;
            }
            if (s1 > s1) {
                std::cout << k[i] << "*x^(" << s1 << ")";
                s1--;
            }
            if (s2 > s1) {
                std::cout << z[i] << "*x^(" << s2 << ")";
                s2--;
            }
            std::cout << " + ";
        }
        std::cout << k[n1] * z[n2];
    }
};