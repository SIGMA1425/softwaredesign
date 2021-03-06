# 再帰的アルゴリズム



## 再帰的アルゴリズム

- 再帰（Recursion）
  - あるものがそれ自身のなかでそれと同じ過程を繰り返し利用する過程。
  - マトリョシカ人形など。
- 再起的アルゴリズム（Recursion algorithm）
  - 対象としている問題を分割し、分割された問題に対して自分自身と同じアルゴリズムを適用するアルゴリズム。



### 例 ）階乗



```c
int fact(int n)
{
  if(n<=0)
    	return 1;
  else
    return n*fact(n-1);
}
```



$$ fact(5) \\=5*fact(4)\\=5*4*fact(3)\\=5*4*3*fact(2)\\=5*4*3*2*fact(1)\\=5*4*3*2*1*fact(0)\\=5*4*3*2*1*1$$



## 再帰呼び出しの終端

- それ以上分解できない問題まで到達したら、そこが再起呼び出しの<span style="color : red">終端</span>となる。
- <span style="color:red">終端</span>は明示的に記述する必要がある。
  - 再帰呼び出しをしないことで<span style="color:red">終端</span>を示す。
- 前項の階乗のアルゴリズムではn<=0である場合が<span style="color:red">終端</span>となる。
- <span style="color:red">無限に繰り返さない</span>ことで。「アルゴリズム」となる。



### 1~xの総和

$$ sum(x) = \begin{cases}0 & (x < 1)\\x + sum(x-1) & (otherwise)\end{cases}$$



### フィボナッチ数列x項目

$$ fib(x) = \begin{cases} x & (0 \leq x \leq 1)\\fib(x-2) + fib(x-1) & (otherwise) \end{cases}$$



### 二項係数bin（$$(x+y)^nのx^ky^{n-k}の係数$$）

$$bin(n,k) = \begin{cases}1 & (k = 0)\\1 & (n=k)\\0 & (k > n)\\bin(n-1, k-1) + bin(n-1, k) & (otherwise)\end{cases}$$





## 再帰と非再帰

- 再起的アルゴリズムは、複雑な過程を簡単に記述する方法rとして採用される。
- ただし、関数呼び出しが多くなったり不必要な計算を行う傾向があるため、効率的ではない。
- 再帰的アルゴリズムを非再帰化することができれば、効率的なアルゴリズムとなる。
- しかし、非再帰化するためには相応のテクニックが必要となる。



## 非再帰化

- メモ化/動的計画法(Dinamic planning : DP)
  - 既に計算した部分問題の結果を変数などに記録しておき、再利用する。

### 例）fibの場合

#### パターン1 記録用変数：x1,x2を用意して逐次更新していく

![スクリーンショット 2019-11-15 12.00.32](/Users/syouma/Pictures/スクショ/スクリーンショット 2019-11-15 12.00.32.png)

#### パターン2 記録用配列：resultaryを用意して、計算済の部分を保存していく

![スクリーンショット 2019-11-15 12.02.48](/Users/syouma/Pictures/スクショ/スクリーンショット 2019-11-15 12.02.48.png)

- パターン1では少ないメモリで計算できたが、コピー回数が多くステップがかさむ。
- パターン2では多いメモリが必要だが、コピー回数が多くステップ数はあまりない。
  - resultaryをグローバル変数としておくと、関数から抜けても配列内の値は保持される。しかし、どこまでが計算済みかを別途記録しておく必要がある。