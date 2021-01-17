--TEST--
trader_apo() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

$fast_period = 14;

var_dump(trader_apo(get_data("high", $data0), $fast_period));

--EXPECT--
array(239) {
  [13]=>
  float(0.711)
  [14]=>
  float(-3.055)
  [15]=>
  float(-2.685)
  [16]=>
  float(-1.427)
  [17]=>
  float(-2.33)
  [18]=>
  float(-2.759)
  [19]=>
  float(-1.785)
  [20]=>
  float(-2.265)
  [21]=>
  float(-3.767)
  [22]=>
  float(-4.514)
  [23]=>
  float(-5.496)
  [24]=>
  float(-6.557)
  [25]=>
  float(-5.87)
  [26]=>
  float(-4.821)
  [27]=>
  float(-2.254)
  [28]=>
  float(-0.184)
  [29]=>
  float(-0.029)
  [30]=>
  float(-0.068)
  [31]=>
  float(-0.762)
  [32]=>
  float(-0.324)
  [33]=>
  float(0.77)
  [34]=>
  float(2.108)
  [35]=>
  float(2.449)
  [36]=>
  float(1.025)
  [37]=>
  float(-0.959)
  [38]=>
  float(-2.091)
  [39]=>
  float(-2.377)
  [40]=>
  float(-2.519)
  [41]=>
  float(-0.94)
  [42]=>
  float(1.464)
  [43]=>
  float(2.152)
  [44]=>
  float(3.259)
  [45]=>
  float(3.68)
  [46]=>
  float(3.545)
  [47]=>
  float(3.489)
  [48]=>
  float(2.499)
  [49]=>
  float(2.378)
  [50]=>
  float(1.584)
  [51]=>
  float(-0.063)
  [52]=>
  float(-0.867)
  [53]=>
  float(-2.664)
  [54]=>
  float(-5.209)
  [55]=>
  float(-4.977)
  [56]=>
  float(-3.369)
  [57]=>
  float(-1.877)
  [58]=>
  float(-0.283)
  [59]=>
  float(1.118)
  [60]=>
  float(1.964)
  [61]=>
  float(1.279)
  [62]=>
  float(1.831)
  [63]=>
  float(3.98)
  [64]=>
  float(4.63)
  [65]=>
  float(4.589)
  [66]=>
  float(4.338)
  [67]=>
  float(2.761)
  [68]=>
  float(1.161)
  [69]=>
  float(0.746)
  [70]=>
  float(-0.602)
  [71]=>
  float(-2.255)
  [72]=>
  float(-3.822)
  [73]=>
  float(-5.349)
  [74]=>
  float(-5.113)
  [75]=>
  float(1.385)
  [76]=>
  float(9.247)
  [77]=>
  float(11.39)
  [78]=>
  float(12.576)
  [79]=>
  float(11.712)
  [80]=>
  float(9.401)
  [81]=>
  float(8.549)
  [82]=>
  float(8.353)
  [83]=>
  float(8.43)
  [84]=>
  float(7.314)
  [85]=>
  float(5.54)
  [86]=>
  float(5.176)
  [87]=>
  float(5.284)
  [88]=>
  float(4.594)
  [89]=>
  float(5.173)
  [90]=>
  float(9.795)
  [91]=>
  float(12.39)
  [92]=>
  float(9.927)
  [93]=>
  float(8.133)
  [94]=>
  float(6.851)
  [95]=>
  float(4.882)
  [96]=>
  float(2.785)
  [97]=>
  float(0.833)
  [98]=>
  float(-1.494)
  [99]=>
  float(-0.817)
  [100]=>
  float(0.538)
  [101]=>
  float(-0.66)
  [102]=>
  float(-2.369)
  [103]=>
  float(-3.463)
  [104]=>
  float(-2.193)
  [105]=>
  float(-1.093)
  [106]=>
  float(1.964)
  [107]=>
  float(3.93)
  [108]=>
  float(3.414)
  [109]=>
  float(1.956)
  [110]=>
  float(-0.215)
  [111]=>
  float(-0.637)
  [112]=>
  float(-0.111)
  [113]=>
  float(2.411)
  [114]=>
  float(3.89)
  [115]=>
  float(3.525)
  [116]=>
  float(4.551)
  [117]=>
  float(6.769)
  [118]=>
  float(5.354)
  [119]=>
  float(3.096)
  [120]=>
  float(3.586)
  [121]=>
  float(3.367)
  [122]=>
  float(2.83)
  [123]=>
  float(5.396)
  [124]=>
  float(7.338)
  [125]=>
  float(6.302)
  [126]=>
  float(6.475)
  [127]=>
  float(6.243)
  [128]=>
  float(6.089)
  [129]=>
  float(6.916)
  [130]=>
  float(7.586)
  [131]=>
  float(7.644)
  [132]=>
  float(6.527)
  [133]=>
  float(5.019)
  [134]=>
  float(3.68)
  [135]=>
  float(3.041)
  [136]=>
  float(-0.131)
  [137]=>
  float(-4.535)
  [138]=>
  float(-6.149)
  [139]=>
  float(-7.818)
  [140]=>
  float(-8.882)
  [141]=>
  float(-7.852)
  [142]=>
  float(-5.581)
  [143]=>
  float(-4.748)
  [144]=>
  float(-4.891)
  [145]=>
  float(-4.259)
  [146]=>
  float(-4.945)
  [147]=>
  float(-5.849)
  [148]=>
  float(-4.444)
  [149]=>
  float(-1.031)
  [150]=>
  float(-0.261)
  [151]=>
  float(-1.994)
  [152]=>
  float(-1.999)
  [153]=>
  float(-1.228)
  [154]=>
  float(-0.809)
  [155]=>
  float(1.124)
  [156]=>
  float(3.163)
  [157]=>
  float(3.828)
  [158]=>
  float(2.113)
  [159]=>
  float(-0.401)
  [160]=>
  float(-0.526)
  [161]=>
  float(-1.026)
  [162]=>
  float(-1.435)
  [163]=>
  float(-0.229)
  [164]=>
  float(0.282)
  [165]=>
  float(-0.066)
  [166]=>
  float(0.179)
  [167]=>
  float(1.284)
  [168]=>
  float(1.498)
  [169]=>
  float(1.989)
  [170]=>
  float(4.664)
  [171]=>
  float(6.451)
  [172]=>
  float(7.525)
  [173]=>
  float(8.449)
  [174]=>
  float(7.215)
  [175]=>
  float(4.44)
  [176]=>
  float(3.379)
  [177]=>
  float(2.324)
  [178]=>
  float(0.097)
  [179]=>
  float(-1.029)
  [180]=>
  float(-2.193)
  [181]=>
  float(-3.919)
  [182]=>
  float(-4.904)
  [183]=>
  float(-5.69)
  [184]=>
  float(-5.77)
  [185]=>
  float(-5.239)
  [186]=>
  float(-6.261)
  [187]=>
  float(-6.408)
  [188]=>
  float(-6.247)
  [189]=>
  float(-6.404)
  [190]=>
  float(-4.469)
  [191]=>
  float(-2.406)
  [192]=>
  float(-3.561)
  [193]=>
  float(-6.276)
  [194]=>
  float(-6.602)
  [195]=>
  float(-5.813)
  [196]=>
  float(-7.513)
  [197]=>
  float(-10.055)
  [198]=>
  float(-9.774)
  [199]=>
  float(-7.774)
  [200]=>
  float(-6.936)
  [201]=>
  float(-4.25)
  [202]=>
  float(-9.996)
  [203]=>
  float(-17.403)
  [204]=>
  float(-14.334)
  [205]=>
  float(-11.733)
  [206]=>
  float(-9.825)
  [207]=>
  float(-8.759)
  [208]=>
  float(-5.776)
  [209]=>
  float(-2.879)
  [210]=>
  float(-2.969)
  [211]=>
  float(-3.596)
  [212]=>
  float(-3.751)
  [213]=>
  float(-4.104)
  [214]=>
  float(-3.314)
  [215]=>
  float(-0.779)
  [216]=>
  float(0.491)
  [217]=>
  float(1.285)
  [218]=>
  float(0.799)
  [219]=>
  float(0.208)
  [220]=>
  float(-0.377)
  [221]=>
  float(-1.096)
  [222]=>
  float(0.583)
  [223]=>
  float(5.257)
  [224]=>
  float(9.521)
  [225]=>
  float(10.901)
  [226]=>
  float(8.427)
  [227]=>
  float(5.559)
  [228]=>
  float(4.744)
  [229]=>
  float(3.351)
  [230]=>
  float(2.574)
  [231]=>
  float(2.849)
  [232]=>
  float(5.877)
  [233]=>
  float(9.534)
  [234]=>
  float(10.966)
  [235]=>
  float(11.35)
  [236]=>
  float(11.11)
  [237]=>
  float(6.093)
  [238]=>
  float(1.1)
  [239]=>
  float(0.202)
  [240]=>
  float(-2.413)
  [241]=>
  float(-2.926)
  [242]=>
  float(-1.804)
  [243]=>
  float(-1.853)
  [244]=>
  float(-2.729)
  [245]=>
  float(-3.079)
  [246]=>
  float(-2.746)
  [247]=>
  float(-2.436)
  [248]=>
  float(-1.679)
  [249]=>
  float(-0.679)
  [250]=>
  float(0.026)
  [251]=>
  float(-0.299)
}