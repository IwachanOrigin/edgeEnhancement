
# edgeEnhancement
画像を読み込み、RGB値を取得し、任意の比率を使用して二次微分を行うことで輪郭を強調します。  
入力画像と比べてみると、画像全体がくっきりはっきりしているような効果を見ることができます。  
エッジを強調するとかいいますね。シャープな画像って表現でも伝わる気がします。  
ラプラシアンフィルタと呼ばれるフィルタに属するプログラムです。  
画像読み込み、GUIにはQtを使用しています。  

## Demo
元画像  
![base](https://user-images.githubusercontent.com/12496951/183280168-77b6db35-4c82-429b-8979-94df9be4807a.PNG)  

比率を2.0とし、輪郭を強調させた画像  
![edgeEnhancement](https://user-images.githubusercontent.com/12496951/183280169-f5bd9563-8bd4-4520-90f8-5191abe9511f.PNG)  


## Dependency
- MSVC 15+  
- Qt 5.13.1

## Build
CMakeLists.txtではQTDIRを環境変数から取得して使用しています。  
また、ここではWSL2とPowerShell、CMakeを使用したビルド方法を記述します。  
CMakeは環境変数のPATHへ追加しています。  

1. このリポジトリをクローンします。  
2. 以下のコマンドでビルドします。  
   ex. VS2017 の場合  
   powershell.exe cmake -S . -B build -G "\\"Visual Studio 15 2017 Win64\\""  
   powershell.exe cmake --build build  

   ex. VS2019以上の場合  
   powershell.exe cmake -S . -B build  
   powershell.exe cmake --build build  

3. 実行時に必要なDLL群はコピーしていません。実行の際には注意してください。


## License
This software is released under the MIT License, see LICENSE.

## References
[C言語で学ぶ実践CG・映像合成](https://www.ohmsha.co.jp/book/9784274500169/)  
[コンピュータ画像処理(改訂2版)](https://www.ohmsha.co.jp/book/9784274228193/)  
[ベッドの下で元カノの帰りを待っていたストーカー化する元カレの写真素材](https://www.pakutaso.com/20160432099post-7538.html)
