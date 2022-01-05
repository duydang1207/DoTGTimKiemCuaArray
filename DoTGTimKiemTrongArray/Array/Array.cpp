
#include <iostream>
#include<string>
#include<chrono>
using namespace std;

struct Array {
	string url;
};
void RandomStringGenerator(string code[], int codeLength)
{
    string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
    int boxLength = box.length();
    for (int i = 0; i < codeLength; i++)
    {
        code[0] = code[0] + box[rand() % boxLength];
    }
}
void SinhURL(string url[])
{
    int k = 1;
    int r = 7;
    int count = 0;
    string a[1];
    a[0] = "https://utex.hcmute.edu.vn";
    string* b = a;
    url[0] = *b;
    for (int m = 0; m < 10; m++)
    {
        a[0] = "https://utex.hcmute.edu.vn/";
        RandomStringGenerator(a, r);
        string* b = a;
        url[k] = *b;
        int temp1 = k;
        for (int h = 0; h < 10; h++)
        {
            k++;
            a[0] = url[temp1] + '/';
            RandomStringGenerator(a, r);
            string* c = a;
            url[k] = *c;
            int temp2 = k;
            for (int l = 0; l < 10; l++)
            {
                k++;
                a[0] = url[temp2] + '/';
                RandomStringGenerator(a, r);
                string* d = a;
                url[k] = *d;
            }
        }
    }
}
void insert(Array* A[], string url)
{
	int i = 0;
	while (A[i]->url != "")i++;
	A[i]->url = url;
}

bool Search(Array* A[],int n, string url)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i]->url == url)
            return true;
    }
    return false;
}

int main()
{
	Array* A[2000];
	int n = 2000;
    string url[2000];
    SinhURL(url);

    int x = 1;
    while (x <= 10)
    {
        for (int i = 0; i < 2000; i++)
            A[i] = new Array;

        for (int i = 0; i < 100*x; i++)
            insert(A, url[i]);
        double sum = 0, max = 0, min = 2000;
        for (int i = 0; i < 100 * x; i++)
        {

            auto begin = chrono::high_resolution_clock().now();
            Search(A, 100 * x, url[i]);
            auto end = chrono::high_resolution_clock().now();

            auto result = chrono::duration_cast<std::chrono::microseconds>(end - begin);
            sum += result.count();
            if (result.count() > max)
                max = result.count();
            if (result.count() < min)
                min = result.count();

        }
        double avg = (double)(sum / (100 * x));
        std::cout << "The number of URLs: " << 100 * x << endl;
        cout << "Max execution time: " << max * 1e-6 << " s" << endl;
        cout << "Min execution time: " << min * 1e-6 << " s" << endl;
        std::cout << "Average execution time: " << avg * 1e-6 << " s" << endl << endl;
        x++;
    }

	return 0;
}

