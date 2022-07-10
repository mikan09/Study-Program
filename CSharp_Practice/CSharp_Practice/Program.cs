using System;
using System.Collections.Generic;

namespace CSharp_Practice
{
    // メモ

    // ■ショートカット

    /*
    Ctrl k,s    ：定型文の挿入 (try文など)★
    Ctrl space  ：入力補間(変数の候補)★
    Ctrl k,i    ：ヒントの表示
    
    Ctrl Alt l  ：ソリューションエクスプローラー
    Ctrl k w    ：ブックマークウィンドウ

    F4          ：プロパティウィンドウ
    Shift Alt Enter ：全画面表示

    Ctrl -       ：
    戻る
    Ctrl Shift - ：進む

    Ctrl F1     ：ヘルプを表示
    Ctrl tab    ：ウィンドウ間を移動★
    Ctrl ← →  ：単語単位で移動★

    Ctrl Shift < ：縮小
    Ctrl Shift > ：拡大

    // 既に使用
    Ctrl Shift l    ：行まるごと削除
    Alt ↑↓        ：行まるごと移動
    Ctrl d          ：行を複製
    Ctrl w          ：単語を選択

    Ctrl k c        ：コメントアウト
    Ctrl k u        ：コメントをはずす

    Ctrl r r        ：変数名等の名前の変更

    F12             ：定義に移動


     */



    class Program
    {
        static void Main( string[] args )
        {
            // 定数
            const string START_MSG = "in C#";

            // 時刻時刻(ローカル)
            DateTime date = DateTime.Now;


            // コンソール出力
            // 文字列補間
            Console.WriteLine( $"Hello World! {START_MSG} {date.ToString( "yyyy/MM/dd hh:mm:ss" )}" );

            // --------------------------------
            // 配列
            // --------------------------------
            int[] vNum = { 1, 2, 3, 4, 5 };

            // 配列要素数でループ
            Console.WriteLine( $"配列要素数({vNum.Length})でループ" );
            for ( byte cnt = 0; cnt < vNum.Length; cnt++ ) {
                Console.Write( $"{vNum[cnt]}," );
            }
            Console.WriteLine();    // 改行

            // foreachでループ
            Console.WriteLine( $"foreachでループ" );
            foreach ( int num in vNum ) {
                Console.Write( $"{num}," );
            }
            Console.WriteLine();    // 改行



            // List<T> 動的配列
            var listColor = new List<string>();
            Console.WriteLine( $"動的配列: 追加前 要素数({listColor.Count})" );
            
            // add() 配列追加
            listColor.Add( "Red" );
            listColor.Add( "Green" );
            listColor.Add( "Blue" );
            foreach ( string color in listColor ) {
                Console.Write( $"{color}," );
            }
            Console.WriteLine();
            Console.WriteLine( $"動的配列: 追加後 要素数({listColor.Count})\n" );
            

            // Remove() 配列削除
            listColor.Remove( "Green" );
            foreach ( string color in listColor ) {
                Console.Write( $"{color}," );
            }
            Console.WriteLine();
            Console.WriteLine( $"動的配列: 削除後 要素数({listColor.Count})\n" );

            // Contains() 存在判定
            string serchColor = "Red";
            if ( listColor.Contains( serchColor ) ) {
                // nameof(変数名) 変数名を文字列変換
                Console.WriteLine( $"{serchColor}は、配列{nameof( listColor )}内に存在します。" );
            } else {
                Console.WriteLine( $"{serchColor}は、配列{nameof( listColor )}内に存在しません。" );
            }





        }
    }
}
