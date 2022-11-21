//#include <iostream>
//#include <vector>
//#include <deque>
//#include <cmath>
//#include <algorithm>
//#include <map>
//#include <string>
//
//using namespace std;
//int max(int a, int b){
//    if(a > b){
//        return a;
//    } else return b;
//}
//int min(int a, int b){
//    if(a < b){
//        return a;
//    } else return b;
//}
//int digit_count(int a){
//    int count = 1;
//    while(a / 10 > 0){
//        a /= 10;
//        count++;
//    }
//    return count;
//}
//int zeroes(int a){
//    int res = 10;
//    while(a--){
//        res *=10;
//    }
//    return res;
//}
//bool fzero(int a){
//    int count = 0;
//    while(a / 10 > 0){
//        if(a % 10 == 0){
//            count++;
//        }
//        a /= 10;
//    }
//    if(count > 0){
//        return false;
//    }
//    else return true;
//}
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    /*   vector<int> a;
//    map<int, int> b;
//    int n;
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        int ac;
//        cin >> ac;
//        a.push_back(ac);
//        b[ac]+=1;
//    }
//    int as;
//    cin >> as;
//    bool t;
//    for (auto [key,value] : b){
//        if(value > 1){
//            t = !t;
//            cout << "Yes " << key << " " << value <<  endl;
//        }
//    }
//    */
//    /*string str;
//    int p=0;
//    vector<string> st;
//    map<string, string> a;
//    cin >> str;
//    string sss;
//    while(str != "END"){
//
//        //a.push_back(str);
//        for(int i = 0; i < str.size(); i++){
//            if(str[i] == 'b' && str[i + 1]=='y' && str[i+2]==' '){
//                p=i+3;
//            }
//        }
//        cout << p << " ";
//        for(int j=p;j<str.size();j++){
//            sss+=str[j];
//        }
//        cin >> str;
//    }
//    cout << sss;
//    int a,b,x,y;
//    cin >> a >> b >> x >> y;
//    int t = 0;
//    int x1=func(a,b),x2=func1(a,b);
//    int y1=func(x,y),y2=func1(x,y);
//    while(x1 != x2){
//        while(x1 != y1){
//            if(x1 < y1){
//                x1++;
//                t++;
//            }
//            else{
//                x1--;
//                t++;
//            }
//        }
//        x1=y2;
//        while(x1 != x2){
//            if(x1 < x2){
//                x1++;
//                t++;
//            }
//            else{
//                x1--;
//                t++;
//            }
//        }
//    }
//    cout << t;*/
//    /* int n,k;
//    cin >> n >> k;
//    deque <int> a;
//    vector<int> b;
//    vector<int> c;
//    for(int i = 0; i < n; i++){
//        int a1;
//        cin >> a1;
//        a.push_back(a1);
//        b.push_back(a1);
//    }
//    sort(b.begin(),b.end());
//    reverse(b.begin(),b.end());
//    for(int i = 0; i < k; i++){
//        c.push_back(b[i]);
//    }
//    int cc = 0;
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < c.size(); j++){
//            if(a[i] != c[j]){
//                cc++;
//            }
//            if(cc == c.size()){
//                a.pop_front();
//                a.push_back(a[i-1]);
//            }
//        }
//        break;
//    }
//    int res = 0,jj=1;
//    for(int i = 1; i < n; i++){
//        int count = 0;
//        for(int j = 0; j < c.size(); j++){
//            if(a[i] != c[j]){
//                count++;
//            }
//            else {
//                jj = 1;
//            }
//            if(count == c.size()){
//                res+=a[i]*jj;
//                jj++;
//            }
//        }
//    }
//    cout << res;*/
//    /*int H,W,h,w;
//    int res = 0;
//    cin >> H >> W >> h >> w;
//    int H1=min(H,W);
//    int W1=max(H,W);
//    int h1=min(h,w);
//    int w1=max(h,w);
//    if(H1 - h1 + W1 - w1 == 0){
//        cout << 0;
//        return 0;
//    }
//    while(H1 - h1 + W1 - w1 != 0){
//        if(h1 > H1 || w1 > W1) {
//            cout << -1;
//            return 0;
//        }
//        if(H1 != h1) {
//            if (H1 <= 2 * h1) {
//                H1 = h1;
//                res++;
//            } else {
//                H1 = H1 - H1 / 2;
//                res++;
//            }
//        }
//        if(W1 != w1) {
//            if (W1 <= 2 * w1) {
//                W1 = w1;
//                res++;
//            } else {
//                W1 = W1 - W1 / 2;
//                res++;
//            }
//        }
//    }
//    cout << res;
//*/
//    /*int t;
//    int n;
//    vector<char> ss;
//    string s;
//    cin >> t;
//    for(int i = 0; i < t; i++){
//        cin >> n >> s;
//        if(n != 5){
//            cout << "NO" << endl;
//        }
//        else{
//            for(int j = 0; j < n; j++){
//                ss.push_back(s[j]);
//            }
//            sort(ss.begin(),ss.end());
//            string sss ="";
//            for(int c = 0; c < n;c++){
//                sss+=ss[c];
//            }
//            if(sss == "Timru"){
//                cout << "YES" << endl;
//            }
//            else {
//                cout << "NO" << endl;
//            }
//            sss="";
//            ss.clear();
//        }
//    }*/
//    /*int t,n;
//    char c;
//    cin >> t;
//    while(t != 0){
//        cin >> n;
//        string ss1="";
//        string ss2="";
//        for(int i = 0; i < n; i++){
//            cin >> c;
//            if(c == 'G' || c == 'B'){
//                ss1+="G";
//            }
//            else {
//                ss1+=c;
//            }
//        }
//        for(int i = 0; i < n; i++){
//            cin >> c;
//            if(c == 'G' || c == 'B'){
//                ss2+="G";
//            }
//            else {
//                ss2+=c;
//            }
//        }
//        if(ss1 == ss2){
//            cout << "YES" << endl;
//        }
//        else {
//            cout << "NO" << endl;
//        }
//
//        t--;
//    }*/
//    /*int t,n;
//    cin >> t;
//    vector<string> word;
//    map<string, int> words;
//    while(t != 0){
//        cin >> n;
//        string s;
//        for(int i = 0; i < 3*n; i++){
//            cin >> s;
//            word.push_back(s);
//        }
//        for(int j = 0; j < 3*n; j++){
//            words[word[j]]++;
//        }
//        int res1 = 0, res2 = 0, res3 = 0;
//        for(int c = 0; c < 3*n; c++){
//            if(c < n){
//                if(words[word[c]] == 1){
//                    res1+=3;
//                }
//                else if(words[word[c]] == 2){
//                    res1+=1;
//                }
//            }
//            if(n <= c && c < 2*n){
//                if(words[word[c]] == 1){
//                    res2+=3;
//                }
//                else if(words[word[c]] == 2){
//                    res2+=1;
//                }
//            }
//            if(2*n <= c && c < 3*n){
//                if(words[word[c]] == 1){
//                    res3+=3;
//                }
//                else if(words[word[c]] == 2){
//                    res3+=1;
//                }
//            }
//        }
//        cout << res1 << " " << res2 << " " << res3 << endl;
//        t--;
//        word.clear();
//        words.clear();
//    }*/
//    /*int t;
//    int a,b,c;
//    cin >> t;
//    while(t--){
//        cin >> a >> b >> c;
//        int res1 = 0, res2 = 0;
//        if (a == 1){
//            cout << 1 << endl;
//        }
//        else if(b > c){
//            res1=a - 1;
//            res2=b - 1;
//            if(res1 > res2){
//                cout << 2 << endl;
//            }
//            else if(res1 == res2){
//                cout << 3 << endl;
//            }
//            else if(res1 < res2){
//                cout << 1 << endl;
//            }
//        }
//        else if(b < c){
//            res1 = a - 1;
//            res2 = (c - b) + (c - 1);
//            if(res1 > res2){
//                cout << 2 << endl;
//            }
//            else if(res1 == res2){
//                cout << 3 << endl;
//            }
//            else if(res1 < res2){
//                cout << 1 << endl;
//            }
//        }
//    }*/
//    /*int q;
//    cin >> q;
//    while(q--) {
//        long long a, t;
//        string s = "";
//        cin >> a >> t;
//        while (a / pow(10, t - 1) > 0 && t > 0) {
//            if (((long long) (a / pow(10, t - 3)) % 10) == 0) {
//                cout << " yres" << endl;
//                cout << (int) (a / pow(10, t - 2)) << endl;
//                s += char(97 + (int) (a / pow(10, t - 2)) - 1);
//                long long p = pow(10, t - 3);
//                a = a % p;
//                cout << a << " " << p << endl;
//                t -= 3;
//            } else {
//                cout << a << " " << char(97 + a / pow(10, t - 1) - 1) << endl;
//                s += char(97 + a / pow(10, t - 1) - 1);
//                long long p = pow(10, t - 1);
//                a = a % p;
//                t--;
//                cout << a << " " << t << endl;
//            }
//            /*if(a / pow(10, t - 1) > 2 || fzero(a) == true || ((a / pow(10, t - 1) == 1) && (((long long)(a / pow(10, t - 3)) % 10) != 0))){
//                cout << a << " " << char(97 + a / pow(10, t - 1) - 1) << endl;
//                s += char(97 + a / pow(10, t - 1) - 1);
//                long long p = pow(10, t - 1);
//                a = a % p;
//                t--;
//                cout << a << " " << t << endl;
//            }
//            else if(((long long)(a / pow(10, t - 3)) % 10) == 0) {
//                    cout << " yres" << endl;
//                    cout << (int)(a / pow(10, t - 2)) << endl;
//                    s += char(97 + (int)(a / pow(10, t - 2)) - 1);
//                    long long p = pow(10, t - 3);
//                    a = a % p;
//                    cout << a << " "<< p << endl;
//                    t -= 3;
//                }
//                //t -= 3;
//
//
//            cout << s << endl;
//        }
//    }
//    */
//    int t;
//    cin >> t;
//    for(int j = 0; j < t; j++){
//        vector<int> a;
//        int ch;
//        cin >> ch;
//        for(int i = 0; i < ch; i++) {
//            a.push_back(i+1);
//        }
//        reverse(a.begin(), a.end());
//        for(int i = 0; i < ch - 1; i++){
//            if((a[i] != a[i+1] + 1 || a[i] != a[i+1] - 1) || (a[i] == i)){
//                swap(a[i],a[i+1]);
//            }
//        }
//        for(auto s : a){
//            cout << s << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
//

#include "math.h"
#include <iostream>
#include <vector>
#include <locale>
#include "stdio.h"
#include <windows.h>
#include "stdlib.h"

using namespace std;

vector<vector<double>> myArray = { {1.0, 0.47, -0.11, 0.55},
                                   {0.42, 1.0, 0.35, 0.17},
                                   {-0.25, 0.67, 1.0, 0.36},
                                   {0.54, -0.32, -0.74, 1.0}
};

vector<double> GaussF(vector<vector<double>> myArray,double f[4]){
    int lines=4,columns=4;
    vector<double> x1;
    int index[lines];           // массив индексов
    for (int i = 0; i < lines; i++)
    {
        index[i] = i;
    }

    // прямая прогонка, приведение к верхнетреугольному виду
    int k = 0;              // вспомогательный счётчик
    double determ = 1;
    while (k < lines)
    {
        // нахождение максимального элемента
        double maxElement = fabs(myArray[k][k]);
        int maxIndex = k;
        for (int j = k; j < columns; j++)
        {
            if (fabs(myArray[k][j]) > maxElement)
            {
                maxElement = fabs(myArray[k][j]);
                maxIndex = j;   // индекс максимального элемента (для перестановки)
            }
        }

        // запоминаем перестановки (чтобы в конце вернутся к первоначальному вектору)
        if (maxIndex != k)
        {
            int tempIndex = index[k];
            index[k] = maxIndex;
            index[maxIndex] = tempIndex;
        }

        // перестановка столбца с максимальным элементом на "первое" место
        for (int i = 0; i < lines; i++)
        {
            double temp = myArray[i][k];
            myArray[i][k] = myArray[i][maxIndex];
            myArray[i][maxIndex] = temp;
        }

        // сам метод Гаусса
        double tempArray = myArray[k][k];
        f[k] /= tempArray;
        for (int j = k+1; j < columns; j++)
        {
            myArray[k][j] /= tempArray;
        }


        for (int i = k + 1; i < lines; i++)
        {
            f[i] -= f[k] * myArray[i][k];
            double temp = myArray[i][k];
            for (int j = k; j < columns; j++)
            {
                myArray[i][j] -= myArray[k][j] * temp;
            }
        }
        determ*=myArray[k][k];
        k++;

    }
    cout << "Determ"<< endl;
    cout << determ << endl;

    // обратная прогонка
    for (int i = lines - 1; i >= 0; i--)
    {
        for (int j = columns - 1; j > i; j--)
        {
            f[i] -= myArray[i][j] * f[j];
        }

    }


    // возвращаемся к первоначальному вектору
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            if (index[j] == i)
            {
                x1.push_back(f[j]);
            }
        }
    }
    return x1;
}
vector<double> GaussS(vector<vector<double>> myArray,double *b1, vector<double> x1){
    int lines=4,columns=4;
    vector<double> as;
    int index[lines];           // массив индексов
    for (int i = 0; i < lines; i++)
    {
        index[i] = i;
    }
    double *b;
    b = new double[4];
    for(int i = 0; i < 4; i++){
        b[i] = b1[i];
    }


    // прямая прогонка, приведение к верхнетреугольному виду
    int k = 0;              // вспомогательный счётчик
    double determ = 1;
    while (k < lines)
    {
        // нахождение максимального элемента
        double maxElement = fabs(myArray[k][k]);
        int maxIndex = k;
        for (int j = k; j < columns; j++)
        {
            if (fabs(myArray[k][j]) > maxElement)
            {
                maxElement = fabs(myArray[k][j]);
                maxIndex = j;   // индекс максимального элемента (для перестановки)
            }
        }

        // запоминаем перестановки (чтобы в конце вернутся к первоначальному вектору)
        if (maxIndex != k)
        {
            int tempIndex = index[k];
            index[k] = maxIndex;
            index[maxIndex] = tempIndex;
        }

        // перестановка столбца с максимальным элементом на "первое" место
        for (int i = 0; i < lines; i++)
        {
            double temp = myArray[i][k];
            myArray[i][k] = myArray[i][maxIndex];
            myArray[i][maxIndex] = temp;
        }

        // сам метод Гаусса
        double tempArray = myArray[k][k];
        b[k] /= tempArray;
        for (int j = k+1; j < columns; j++)
        {
            myArray[k][j] /= tempArray;
        }


        for (int i = k + 1; i < lines; i++)
        {
            b[i] -= b[k] * myArray[i][k];
            double temp = myArray[i][k];
            for (int j = k; j < columns; j++)
            {
                myArray[i][j] -= myArray[k][j] * temp;
            }
        }
        determ*=myArray[k][k];
        k++;

    }

    // обратная прогонка
    for (int i = lines - 1; i >= 0; i--)
    {
        for (int j = columns - 1; j > i; j--)
        {
            b[i] -= myArray[i][j] * b[j];
        }

    }


    // возвращаемся к первоначальному вектору
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            if (index[j] == i)
            {
                as.push_back(b[j]);
            }
        }
    }

    delete[] b;
    return as;
}
void INVERSE (vector<vector<double>>& myArray, vector<vector<double>>&y){
    int i, j;
    double *b;
    b = new double[4];
    vector<double> as;
    vector<double> sas;
    for (i = 0; i<4; i++){
        for (j = 0; j<4; j++)
            if (j == i)
                b[j] = 1;
            else b[j] = 0;


         as= GaussS(myArray,b,as);
         for (j = 0; j < 4; j++) {
             sas.push_back(as[j]);
         }
         y.push_back(as);
    }
    delete[] b;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const int lines = 4;        // задание размера массива
    const int columns = 4;
    double f[lines] = { 1.09, 2.87, 3.65, 4.43 };
    double f1[lines] = { 1.09, 2.87, 3.65, 4.43 };
    vector<double> otvet;
    vector<vector<double>> y1;
    vector<double> d(4);

    otvet = GaussF(myArray,f);
    cout << endl;
    int cc = 1;
    cout << "reshenie\n";
    for(auto s : otvet){
        cout<< "x" <<cc++ << "= "<< s << " ";
    }
    cout << endl;
    for(int i = 0; i < lines; i++){
        d[i]=0;
        for(int j = 0; j < columns; j++){
            d[i] += myArray[i][j]*otvet[j];
        }
    }
    cout << "\nvector nevyazki" << endl;
    for(int i = 0; i < 4; i++){
        cout<<fixed <<  d[i] - f1[i] << endl;
    }
    cout << endl;
    INVERSE(myArray,y1);
    cout << "inverse matrix" << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << y1[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "=======================================";
    return 0;
}
//
//#include<iostream>
//#include<vector>
//#include<math.h>
//#include<iomanip>
//#include <ctime>
//#include <map>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//int opred(string s, int n, int pos){
//    int col;
//    vector<int> vec;
//    bool flag;
//    int rast =0;
//    string ss = s;
//    reverse(ss.begin(),ss.end());
//    int temo = ss.find('1');
//    for (int i = pos; i < s.size() - temo; i++) {
//        col = 0;
//        flag = true;
//        if (s[i] == '1') {
//            //cout << "yes=" << i << endl;
//            while (flag) {
//                for (int j = i + 1; j < s.size() && flag; j++) {
//                    if (s[j] == '1') {
//                        col++;
//                        //cout << col << endl;
//                    }
//                    if (col == n) {
//                        cout << col << endl;
//                        //rast = (j - i) * 2;
//                        return rast;
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}
//
//
//int main() {
//    int N;
//    cin >> N;
//    vector<long long> a;
//    vector<long long> b;
//    for(int i = 0; i< N; i++){
//        int temp;
//        cin >> temp;
//        if(temp >= 0){
//            a.push_back(temp);
//        }
//        else{
//            b.push_back(temp);
//        }
//    }
//    sort(a.begin(),a.end());
//    sort(b.begin(),b.end());
//    long long maxabs;
//    if(a.size() > 0 && b.size() > 0){
//        if(a[a.size()-1] > abs(b[0])) {
//            if(a.size() == 1){
//                maxabs=b[0];
//                b.erase(b.begin());
//            }
//            else {
//                maxabs = a[a.size() - 1];
//                a.pop_back();
//            }
//        }
//        else{
//            if(b.size() == 1 && a[a.size() - 1] != 0){
//                maxabs = a[a.size()-1];
//                a.pop_back();
//            }
//            else {
//                maxabs = b[0];
//                b.erase(b.begin());
//            }
//        }
//    }
//    else if(b.size() == 0){
//        maxabs = a[a.size() -1];
//        a.pop_back();
//    }
//    else{
//        maxabs = b[0];
//        b.erase(b.begin());
//    }
//    if(maxabs == 0){
//        cout << "NO";
//        return 0;
//    }
//    if(a.size() > 0 && b.size() > 0){
//        cout << "YES" << endl;
//        cout << b[b.size()-1] << " " << maxabs <<" "<< a[0];
//    }
//    else if(a.size() == 0){
//        if(maxabs*maxabs - 4 * b[b.size()-1]*b[b.size()-2] >= 0){
//            cout << "YES" << endl;
//            cout << b[b.size()-1] << " " << maxabs <<" "<< b[b.size()-2];
//        }
//        else cout << "NO";
//    }
//    else if(b.size() == 0){
//        if(a[0] == 0 && a[1] == 0){
//            cout << "YES" << endl;
//            cout << maxabs << " " << a[0] << " " << a[1];
//        }else if(a[0] == 0 && a[1] != 0 ){
//            cout << "YES" << endl;
//            cout << maxabs << " " << a[1] << " " << a[0];
//        }else if(maxabs*maxabs - 4 * a[0]*a[1] >= 0){
//            cout << "YES" << endl;
//            cout << a[1] << " " << maxabs <<" "<< a[0];
//        }
//        else cout << "NO";
//    }
//
//    return 0;
//}


