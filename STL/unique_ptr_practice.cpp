// PrgramingStudy.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// 参考：
// unique_ptrやshared_ptrなど https://qiita.com/hmito/items/db3b14917120b285112f
// 本ソース：https://programming-place.net/ppp/contents/modern_cpp/library/003.html

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int n):mNum(n)
    {
        std::cout << "Constructor" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "Destructor" << std::endl;
    }

    inline void SetNum( int n )
    {
        mNum = n;
    }
    inline int GetNum() const
    {
        return mNum;
    }
private:
    int mNum;
};

int main()
{
    // ■初期化と破棄
    /*std::unique_ptr のコンストラクタに、生のポインタを渡すと、そのポインタが指しているリソースの解放を std::unique_ptr に任せることになります。
    言い換えると、std::unique_ptr がリソースの管理権限を持ちます。
    このような権限を、所有権という言葉で表現します。*/

    std::unique_ptr<MyClass> p( new MyClass(10) );

    // ■ポインタを取得
    // 管理している生のポインタは、getメンバ関数を使って取得できます。
    // この関数は、ポインタを管理していないときには nullptr を返します。
    std::unique_ptr<int> p1( new int( 100 ) );

    int* rawPtr = p1.get();
    std::cout << *rawPtr << std::endl;

    std::unique_ptr<int> p2;
    rawPtr = p2.get();
    if ( rawPtr == nullptr ) {
        std::cout << "null" << std::endl;
    }
    else {
        std::cout << "not null" << std::endl;
    }

    // ■ポインタ操作
    // 配列版でない std::unique_ptr は、生のポインタと同じように、*演算子や ->演算子を使えます。
    std::unique_ptr<MyClass> p3( new MyClass( 100 ) );

    const MyClass& c = *p3;
    p3->SetNum( 200 );

    std::cout << p3->GetNum() << std::endl;
    std::cout << c.GetNum() << std::endl;

    /*演算子は、管理しているポインタが指す先にあるものを左辺値参照で返します。いわゆるポインタの間接参照を実現します。->演算子は、管理しているポインタを通して、指す先にあるものを操作するときに使います。
    当然、ポインタを管理していないときにこれらの操作を行うと、未定義の動作となってしまうので注意してください。
    ポインタを管理しているかどうかを調べるには、getメンバ関数が nullptr を返さないことを確認するか、bool型への型変換演算子（【言語解説】第９章）を利用して、以下のように問い合わせます。*/
    // std::unique_ptr の p がポインタを管理しているか？
    // if ( p ) {}

    // ■ポインタを再設定
    // resetメンバ関数を使うと、管理対象のポインタを変更できます。もともと何らかのポインタを管理していた場合は、先に解放処理が行われます。
    // また、実引数がない resetメンバ関数を呼ぶか、実引数に nullptr を指定すると、何も管理していない状態にできます。こちらも、もともと何らかのポインタを管理していた場合は、解放処理が行われます。
    std::unique_ptr<MyClass> p4( new MyClass(4) );
    std::cout << p4->GetNum() << std::endl;

    p4.reset( new MyClass(8) );
    std::cout << p4->GetNum() << std::endl;
    p4.reset();
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
