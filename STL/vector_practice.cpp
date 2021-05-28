#include <iostream>
#include <vector>

void OutputVector(std::vector<int> v);

int main()
{
    std::cout << "Hello World!\n";
    //int n;
    //std::cin >> n;
    //std::cout << n << "\n";

    size_t nSize;

    // 要素数10のベクタ変数を定義
    std::vector<int> v(10);

    // ベクタの要素数を取得
    nSize = v.size();  // 10
    printf("v.size:%d\n", nSize);

    // ベクタの要素へのアクセス
    v[0] = 100; // v = [100]

    // ベクタの末尾に要素を追加
    for (int i = 0; i < 4; i++) {
        v.push_back(i);  // v = [0,1,2,3] 
    }
    OutputVector(v);

    // ベクタが空ならばtrue、それ以外はfalseを返す
    // v.empty();
    printf("v.empty():%d\n", v.empty());

    // ベクタの最終要素を削除
    v.pop_back();  // v = [1,2,3] => v = [1,2]
    OutputVector(v);

    // 2要素目の直後に10個の要素'x'を挿入
    v.insert(v.begin() + 2, 10, 'x');
    OutputVector(v);


    // 3番目から10個分の要素を削除
    v.erase(v.begin() + 2, v.begin() + 12);
    OutputVector(v);
}

void OutputVector( std::vector<int> v ) {
    for ( auto itr = v.begin(); itr != v.end();itr++ ) {
        printf("%d, ",*itr);
    }
    printf("\n");
}