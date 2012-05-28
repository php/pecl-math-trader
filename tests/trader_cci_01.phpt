--TEST--
trader_cci() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "data.php";
include "func.php";

var_dump(trader_cci(
	get_data("high", $data0),
	get_data("low", $data0),
	get_data("close", $data0),
	14
));

--EXPECT--
array(226) {
  [13]=>
  float(-123.064)
  [14]=>
  float(-134.414)
  [15]=>
  float(-39.173)
  [16]=>
  float(-86.058)
  [17]=>
  float(-98.712)
  [18]=>
  float(-51.034)
  [19]=>
  float(-55.28)
  [20]=>
  float(-102.462)
  [21]=>
  float(-117.739)
  [22]=>
  float(-140.388)
  [23]=>
  float(-165.807)
  [24]=>
  float(-148.807)
  [25]=>
  float(-140.034)
  [26]=>
  float(-98.977)
  [27]=>
  float(0.216)
  [28]=>
  float(-15.981)
  [29]=>
  float(3.806)
  [30]=>
  float(-30.265)
  [31]=>
  float(2.665)
  [32]=>
  float(5.982)
  [33]=>
  float(80.838)
  [34]=>
  float(120.219)
  [35]=>
  float(76.907)
  [36]=>
  float(9.769)
  [37]=>
  float(-56.263)
  [38]=>
  float(-99.313)
  [39]=>
  float(-97.769)
  [40]=>
  float(-139.933)
  [41]=>
  float(14.426)
  [42]=>
  float(114.827)
  [43]=>
  float(131.813)
  [44]=>
  float(154.907)
  [45]=>
  float(119.609)
  [46]=>
  float(124.476)
  [47]=>
  float(63.649)
  [48]=>
  float(67.485)
  [49]=>
  float(70.93)
  [50]=>
  float(30.594)
  [51]=>
  float(-9.902)
  [52]=>
  float(-87.459)
  [53]=>
  float(-140.493)
  [54]=>
  float(-171.626)
  [55]=>
  float(-110.255)
  [56]=>
  float(-63.535)
  [57]=>
  float(-36.948)
  [58]=>
  float(20.256)
  [59]=>
  float(49.947)
  [60]=>
  float(51.573)
  [61]=>
  float(27.263)
  [62]=>
  float(111.457)
  [63]=>
  float(132.287)
  [64]=>
  float(122.917)
  [65]=>
  float(118.143)
  [66]=>
  float(105.457)
  [67]=>
  float(57.1)
  [68]=>
  float(29.864)
  [69]=>
  float(3.016)
  [70]=>
  float(-74.026)
  [71]=>
  float(-159.737)
  [72]=>
  float(-202.294)
  [73]=>
  float(-155.909)
  [74]=>
  float(-103.556)
  [75]=>
  float(163.863)
  [76]=>
  float(170.431)
  [77]=>
  float(185.255)
  [78]=>
  float(161.89)
  [79]=>
  float(104.398)
  [80]=>
  float(83.746)
  [81]=>
  float(79.203)
  [82]=>
  float(77.476)
  [83]=>
  float(79.001)
  [84]=>
  float(62.682)
  [85]=>
  float(56.699)
  [86]=>
  float(79.175)
  [87]=>
  float(116.052)
  [88]=>
  float(142.82)
  [89]=>
  float(161.558)
  [90]=>
  float(272.618)
  [91]=>
  float(177.272)
  [92]=>
  float(120.45)
  [93]=>
  float(110.339)
  [94]=>
  float(77.443)
  [95]=>
  float(54.6)
  [96]=>
  float(29.495)
  [97]=>
  float(-13.06)
  [98]=>
  float(-41.546)
  [99]=>
  float(16.307)
  [100]=>
  float(-4.044)
  [101]=>
  float(-3.436)
  [102]=>
  float(-95.483)
  [103]=>
  float(-93.136)
  [104]=>
  float(-66.803)
  [105]=>
  float(-10.29)
  [106]=>
  float(151.338)
  [107]=>
  float(83.321)
  [108]=>
  float(103.833)
  [109]=>
  float(4.325)
  [110]=>
  float(-16.534)
  [111]=>
  float(3.187)
  [112]=>
  float(38.32)
  [113]=>
  float(160.006)
  [114]=>
  float(126.001)
  [115]=>
  float(107.807)
  [116]=>
  float(165.266)
  [117]=>
  float(143.881)
  [118]=>
  float(90.215)
  [119]=>
  float(77.457)
  [120]=>
  float(89.305)
  [121]=>
  float(63.499)
  [122]=>
  float(76.687)
  [123]=>
  float(146.578)
  [124]=>
  float(167.586)
  [125]=>
  float(171.897)
  [126]=>
  float(146.955)
  [127]=>
  float(120.795)
  [128]=>
  float(120.977)
  [129]=>
  float(134.068)
  [130]=>
  float(126.292)
  [131]=>
  float(112.159)
  [132]=>
  float(96.274)
  [133]=>
  float(73.729)
  [134]=>
  float(65.727)
  [135]=>
  float(45.768)
  [136]=>
  float(-117.065)
  [137]=>
  float(-123.432)
  [138]=>
  float(-168.055)
  [139]=>
  float(-151.476)
  [140]=>
  float(-129.889)
  [141]=>
  float(-85.175)
  [142]=>
  float(-48.888)
  [143]=>
  float(-66.118)
  [144]=>
  float(-58.693)
  [145]=>
  float(-84.422)
  [146]=>
  float(-124.83)
  [147]=>
  float(-129.745)
  [148]=>
  float(-89.527)
  [149]=>
  float(-20.908)
  [150]=>
  float(-50.239)
  [151]=>
  float(-112.461)
  [152]=>
  float(-34.498)
  [153]=>
  float(-39.355)
  [154]=>
  float(7.646)
  [155]=>
  float(116.547)
  [156]=>
  float(158.549)
  [157]=>
  float(83.393)
  [158]=>
  float(0.731)
  [159]=>
  float(-19.822)
  [160]=>
  float(26.57)
  [161]=>
  float(-50.582)
  [162]=>
  float(-44.717)
  [163]=>
  float(8.504)
  [164]=>
  float(20.072)
  [165]=>
  float(2.301)
  [166]=>
  float(28.038)
  [167]=>
  float(127.753)
  [168]=>
  float(51.246)
  [169]=>
  float(165.643)
  [170]=>
  float(206.127)
  [171]=>
  float(169.399)
  [172]=>
  float(169.587)
  [173]=>
  float(152.544)
  [174]=>
  float(91.097)
  [175]=>
  float(72.848)
  [176]=>
  float(63.511)
  [177]=>
  float(16.948)
  [178]=>
  float(-62.967)
  [179]=>
  float(-30.794)
  [180]=>
  float(-73.936)
  [181]=>
  float(-118.563)
  [182]=>
  float(-152.103)
  [183]=>
  float(-129.617)
  [184]=>
  float(-102.868)
  [185]=>
  float(-94.092)
  [186]=>
  float(-117.19)
  [187]=>
  float(-105.663)
  [188]=>
  float(-137.612)
  [189]=>
  float(-111.141)
  [190]=>
  float(-56.097)
  [191]=>
  float(-72.058)
  [192]=>
  float(-133.042)
  [193]=>
  float(-190.533)
  [194]=>
  float(-131.53)
  [195]=>
  float(-157.976)
  [196]=>
  float(-189.313)
  [197]=>
  float(-154.938)
  [198]=>
  float(-118.988)
  [199]=>
  float(-100.74)
  [200]=>
  float(-84.663)
  [201]=>
  float(-50.347)
  [202]=>
  float(-222.764)
  [203]=>
  float(-161.606)
  [204]=>
  float(-142.289)
  [205]=>
  float(-97.545)
  [206]=>
  float(-90.745)
  [207]=>
  float(-67.739)
  [208]=>
  float(-31.938)
  [209]=>
  float(-29.798)
  [210]=>
  float(-47.592)
  [211]=>
  float(-48.21)
  [212]=>
  float(-78.267)
  [213]=>
  float(-88.853)
  [214]=>
  float(-58.278)
  [215]=>
  float(-13.902)
  [216]=>
  float(75.239)
  [217]=>
  float(55.009)
  [218]=>
  float(17.24)
  [219]=>
  float(6.648)
  [220]=>
  float(-22.241)
  [221]=>
  float(-39.452)
  [222]=>
  float(105.508)
  [223]=>
  float(298.543)
  [224]=>
  float(270.811)
  [225]=>
  float(185.82)
  [226]=>
  float(96.142)
  [227]=>
  float(92.454)
  [228]=>
  float(67.109)
  [229]=>
  float(46.034)
  [230]=>
  float(41.663)
  [231]=>
  float(57.814)
  [232]=>
  float(135.973)
  [233]=>
  float(184.93)
  [234]=>
  float(179.484)
  [235]=>
  float(157.387)
  [236]=>
  float(99.803)
  [237]=>
  float(7.667)
  [238]=>
  float(7.44)
}
