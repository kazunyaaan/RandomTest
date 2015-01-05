RandomTest
==========

C++ dSFMT Test Random class &amp; Distribution class

任意分布乱数生成クラス



乱数生成アルゴリズムとして，
Double precision SIMD-oriented Fast Mersenne Twister (dSFMT)を使用しています。
(http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/SFMT/index-jp.html#dSFMT)

$ wget http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/SFMT/dSFMT-src-2.2.3.tar.gz
$ tar zxvf dSFMT-src-2.2.3.tar.gz


$ make all && make run
./test
    0	 0.057207
    1	 -0.618570
    2	 1.334336
    3	 0.347777
    4	 0.944551
