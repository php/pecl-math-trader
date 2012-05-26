--TEST--
trader_aroon() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "data.php";
include "func.php";

$fast_period = 14;

var_dump(trader_aroon(get_data("high", $data0), get_data("low", $data0), $fast_period));
--EXPECT--
array(2) {
  [0]=>
  array(224) {
    [14]=>
    float(100)
    [15]=>
    float(92.857)
    [16]=>
    float(85.714)
    [17]=>
    float(78.571)
    [18]=>
    float(71.428)
    [19]=>
    float(64.285)
    [20]=>
    float(57.142)
    [21]=>
    float(100)
    [22]=>
    float(100)
    [23]=>
    float(100)
    [24]=>
    float(100)
    [25]=>
    float(100)
    [26]=>
    float(92.857)
    [27]=>
    float(85.714)
    [28]=>
    float(78.571)
    [29]=>
    float(71.428)
    [30]=>
    float(64.285)
    [31]=>
    float(57.142)
    [32]=>
    float(50)
    [33]=>
    float(42.857)
    [34]=>
    float(35.714)
    [35]=>
    float(28.571)
    [36]=>
    float(21.428)
    [37]=>
    float(14.285)
    [38]=>
    float(7.142)
    [39]=>
    float(0)
    [40]=>
    float(0)
    [41]=>
    float(92.857)
    [42]=>
    float(85.714)
    [43]=>
    float(78.571)
    [44]=>
    float(71.428)
    [45]=>
    float(64.285)
    [46]=>
    float(57.142)
    [47]=>
    float(50)
    [48]=>
    float(42.857)
    [49]=>
    float(35.714)
    [50]=>
    float(28.571)
    [51]=>
    float(21.428)
    [52]=>
    float(14.285)
    [53]=>
    float(7.142)
    [54]=>
    float(100)
    [55]=>
    float(92.857)
    [56]=>
    float(85.714)
    [57]=>
    float(78.571)
    [58]=>
    float(71.428)
    [59]=>
    float(64.285)
    [60]=>
    float(57.142)
    [61]=>
    float(50)
    [62]=>
    float(42.857)
    [63]=>
    float(35.714)
    [64]=>
    float(28.571)
    [65]=>
    float(21.428)
    [66]=>
    float(14.285)
    [67]=>
    float(7.142)
    [68]=>
    float(0)
    [69]=>
    float(0)
    [70]=>
    float(0)
    [71]=>
    float(100)
    [72]=>
    float(100)
    [73]=>
    float(100)
    [74]=>
    float(92.857)
    [75]=>
    float(85.714)
    [76]=>
    float(78.571)
    [77]=>
    float(71.428)
    [78]=>
    float(64.285)
    [79]=>
    float(57.142)
    [80]=>
    float(50)
    [81]=>
    float(42.857)
    [82]=>
    float(35.714)
    [83]=>
    float(28.571)
    [84]=>
    float(21.428)
    [85]=>
    float(14.285)
    [86]=>
    float(7.142)
    [87]=>
    float(0)
    [88]=>
    float(0)
    [89]=>
    float(0)
    [90]=>
    float(0)
    [91]=>
    float(0)
    [92]=>
    float(21.428)
    [93]=>
    float(14.285)
    [94]=>
    float(7.142)
    [95]=>
    float(0)
    [96]=>
    float(0)
    [97]=>
    float(7.142)
    [98]=>
    float(0)
    [99]=>
    float(0)
    [100]=>
    float(0)
    [101]=>
    float(14.285)
    [102]=>
    float(7.142)
    [103]=>
    float(0)
    [104]=>
    float(92.857)
    [105]=>
    float(85.714)
    [106]=>
    float(78.571)
    [107]=>
    float(71.428)
    [108]=>
    float(64.285)
    [109]=>
    float(57.142)
    [110]=>
    float(50)
    [111]=>
    float(42.857)
    [112]=>
    float(35.714)
    [113]=>
    float(28.571)
    [114]=>
    float(21.428)
    [115]=>
    float(14.285)
    [116]=>
    float(7.142)
    [117]=>
    float(0)
    [118]=>
    float(0)
    [119]=>
    float(0)
    [120]=>
    float(28.571)
    [121]=>
    float(21.428)
    [122]=>
    float(14.285)
    [123]=>
    float(7.142)
    [124]=>
    float(0)
    [125]=>
    float(0)
    [126]=>
    float(0)
    [127]=>
    float(0)
    [128]=>
    float(0)
    [129]=>
    float(0)
    [130]=>
    float(21.428)
    [131]=>
    float(14.285)
    [132]=>
    float(7.142)
    [133]=>
    float(0)
    [134]=>
    float(7.142)
    [135]=>
    float(0)
    [136]=>
    float(0)
    [137]=>
    float(0)
    [138]=>
    float(100)
    [139]=>
    float(100)
    [140]=>
    float(92.857)
    [141]=>
    float(85.714)
    [142]=>
    float(78.571)
    [143]=>
    float(71.428)
    [144]=>
    float(64.285)
    [145]=>
    float(100)
    [146]=>
    float(100)
    [147]=>
    float(100)
    [148]=>
    float(100)
    [149]=>
    float(92.857)
    [150]=>
    float(85.714)
    [151]=>
    float(78.571)
    [152]=>
    float(71.428)
    [153]=>
    float(64.285)
    [154]=>
    float(57.142)
    [155]=>
    float(50)
    [156]=>
    float(42.857)
    [157]=>
    float(35.714)
    [158]=>
    float(28.571)
    [159]=>
    float(21.428)
    [160]=>
    float(14.285)
    [161]=>
    float(7.142)
    [162]=>
    float(0)
    [163]=>
    float(14.285)
    [164]=>
    float(7.142)
    [165]=>
    float(0)
    [166]=>
    float(0)
    [167]=>
    float(64.285)
    [168]=>
    float(57.142)
    [169]=>
    float(50)
    [170]=>
    float(42.857)
    [171]=>
    float(35.714)
    [172]=>
    float(28.571)
    [173]=>
    float(21.428)
    [174]=>
    float(14.285)
    [175]=>
    float(7.142)
    [176]=>
    float(0)
    [177]=>
    float(0)
    [178]=>
    float(7.142)
    [179]=>
    float(0)
    [180]=>
    float(0)
    [181]=>
    float(78.571)
    [182]=>
    float(100)
    [183]=>
    float(100)
    [184]=>
    float(92.857)
    [185]=>
    float(85.714)
    [186]=>
    float(100)
    [187]=>
    float(100)
    [188]=>
    float(100)
    [189]=>
    float(92.857)
    [190]=>
    float(85.714)
    [191]=>
    float(78.571)
    [192]=>
    float(100)
    [193]=>
    float(100)
    [194]=>
    float(92.857)
    [195]=>
    float(100)
    [196]=>
    float(100)
    [197]=>
    float(100)
    [198]=>
    float(100)
    [199]=>
    float(92.857)
    [200]=>
    float(85.714)
    [201]=>
    float(78.571)
    [202]=>
    float(100)
    [203]=>
    float(92.857)
    [204]=>
    float(85.714)
    [205]=>
    float(78.571)
    [206]=>
    float(71.428)
    [207]=>
    float(64.285)
    [208]=>
    float(57.142)
    [209]=>
    float(50)
    [210]=>
    float(42.857)
    [211]=>
    float(35.714)
    [212]=>
    float(28.571)
    [213]=>
    float(21.428)
    [214]=>
    float(14.285)
    [215]=>
    float(7.142)
    [216]=>
    float(0)
    [217]=>
    float(64.285)
    [218]=>
    float(57.142)
    [219]=>
    float(50)
    [220]=>
    float(42.857)
    [221]=>
    float(35.714)
    [222]=>
    float(28.571)
    [223]=>
    float(21.428)
    [224]=>
    float(14.285)
    [225]=>
    float(7.142)
    [226]=>
    float(0)
    [227]=>
    float(0)
    [228]=>
    float(0)
    [229]=>
    float(0)
    [230]=>
    float(35.714)
    [231]=>
    float(28.571)
    [232]=>
    float(21.428)
    [233]=>
    float(14.285)
    [234]=>
    float(7.142)
    [235]=>
    float(0)
    [236]=>
    float(0)
    [237]=>
    float(0)
  }
  [1]=>
  array(224) {
    [14]=>
    float(78.571)
    [15]=>
    float(71.428)
    [16]=>
    float(64.285)
    [17]=>
    float(57.142)
    [18]=>
    float(50)
    [19]=>
    float(42.857)
    [20]=>
    float(35.714)
    [21]=>
    float(28.571)
    [22]=>
    float(21.428)
    [23]=>
    float(14.285)
    [24]=>
    float(7.142)
    [25]=>
    float(0)
    [26]=>
    float(0)
    [27]=>
    float(21.428)
    [28]=>
    float(14.285)
    [29]=>
    float(7.142)
    [30]=>
    float(0)
    [31]=>
    float(14.285)
    [32]=>
    float(7.142)
    [33]=>
    float(0)
    [34]=>
    float(0)
    [35]=>
    float(92.857)
    [36]=>
    float(85.714)
    [37]=>
    float(78.571)
    [38]=>
    float(71.428)
    [39]=>
    float(64.285)
    [40]=>
    float(57.142)
    [41]=>
    float(50)
    [42]=>
    float(42.857)
    [43]=>
    float(100)
    [44]=>
    float(100)
    [45]=>
    float(92.857)
    [46]=>
    float(100)
    [47]=>
    float(92.857)
    [48]=>
    float(85.714)
    [49]=>
    float(78.571)
    [50]=>
    float(71.428)
    [51]=>
    float(64.285)
    [52]=>
    float(57.142)
    [53]=>
    float(50)
    [54]=>
    float(42.857)
    [55]=>
    float(35.714)
    [56]=>
    float(28.571)
    [57]=>
    float(21.428)
    [58]=>
    float(14.285)
    [59]=>
    float(7.142)
    [60]=>
    float(0)
    [61]=>
    float(14.285)
    [62]=>
    float(100)
    [63]=>
    float(100)
    [64]=>
    float(100)
    [65]=>
    float(100)
    [66]=>
    float(100)
    [67]=>
    float(92.857)
    [68]=>
    float(85.714)
    [69]=>
    float(78.571)
    [70]=>
    float(71.428)
    [71]=>
    float(64.285)
    [72]=>
    float(57.142)
    [73]=>
    float(50)
    [74]=>
    float(42.857)
    [75]=>
    float(100)
    [76]=>
    float(100)
    [77]=>
    float(100)
    [78]=>
    float(100)
    [79]=>
    float(92.857)
    [80]=>
    float(85.714)
    [81]=>
    float(78.571)
    [82]=>
    float(71.428)
    [83]=>
    float(100)
    [84]=>
    float(92.857)
    [85]=>
    float(85.714)
    [86]=>
    float(100)
    [87]=>
    float(100)
    [88]=>
    float(100)
    [89]=>
    float(100)
    [90]=>
    float(100)
    [91]=>
    float(92.857)
    [92]=>
    float(85.714)
    [93]=>
    float(78.571)
    [94]=>
    float(71.428)
    [95]=>
    float(64.285)
    [96]=>
    float(57.142)
    [97]=>
    float(50)
    [98]=>
    float(42.857)
    [99]=>
    float(35.714)
    [100]=>
    float(28.571)
    [101]=>
    float(21.428)
    [102]=>
    float(14.285)
    [103]=>
    float(7.142)
    [104]=>
    float(0)
    [105]=>
    float(0)
    [106]=>
    float(100)
    [107]=>
    float(92.857)
    [108]=>
    float(85.714)
    [109]=>
    float(78.571)
    [110]=>
    float(71.428)
    [111]=>
    float(64.285)
    [112]=>
    float(57.142)
    [113]=>
    float(50)
    [114]=>
    float(100)
    [115]=>
    float(92.857)
    [116]=>
    float(100)
    [117]=>
    float(100)
    [118]=>
    float(92.857)
    [119]=>
    float(85.714)
    [120]=>
    float(78.571)
    [121]=>
    float(71.428)
    [122]=>
    float(64.285)
    [123]=>
    float(100)
    [124]=>
    float(92.857)
    [125]=>
    float(100)
    [126]=>
    float(100)
    [127]=>
    float(92.857)
    [128]=>
    float(100)
    [129]=>
    float(100)
    [130]=>
    float(100)
    [131]=>
    float(100)
    [132]=>
    float(92.857)
    [133]=>
    float(85.714)
    [134]=>
    float(78.571)
    [135]=>
    float(71.428)
    [136]=>
    float(64.285)
    [137]=>
    float(57.142)
    [138]=>
    float(50)
    [139]=>
    float(42.857)
    [140]=>
    float(35.714)
    [141]=>
    float(28.571)
    [142]=>
    float(21.428)
    [143]=>
    float(14.285)
    [144]=>
    float(7.142)
    [145]=>
    float(0)
    [146]=>
    float(21.428)
    [147]=>
    float(14.285)
    [148]=>
    float(7.142)
    [149]=>
    float(0)
    [150]=>
    float(0)
    [151]=>
    float(0)
    [152]=>
    float(28.571)
    [153]=>
    float(21.428)
    [154]=>
    float(14.285)
    [155]=>
    float(7.142)
    [156]=>
    float(0)
    [157]=>
    float(100)
    [158]=>
    float(92.857)
    [159]=>
    float(85.714)
    [160]=>
    float(78.571)
    [161]=>
    float(71.428)
    [162]=>
    float(64.285)
    [163]=>
    float(57.142)
    [164]=>
    float(50)
    [165]=>
    float(42.857)
    [166]=>
    float(35.714)
    [167]=>
    float(28.571)
    [168]=>
    float(21.428)
    [169]=>
    float(100)
    [170]=>
    float(100)
    [171]=>
    float(100)
    [172]=>
    float(100)
    [173]=>
    float(100)
    [174]=>
    float(92.857)
    [175]=>
    float(85.714)
    [176]=>
    float(78.571)
    [177]=>
    float(71.428)
    [178]=>
    float(64.285)
    [179]=>
    float(57.142)
    [180]=>
    float(50)
    [181]=>
    float(42.857)
    [182]=>
    float(35.714)
    [183]=>
    float(28.571)
    [184]=>
    float(21.428)
    [185]=>
    float(14.285)
    [186]=>
    float(7.142)
    [187]=>
    float(0)
    [188]=>
    float(0)
    [189]=>
    float(7.142)
    [190]=>
    float(0)
    [191]=>
    float(0)
    [192]=>
    float(0)
    [193]=>
    float(0)
    [194]=>
    float(0)
    [195]=>
    float(7.142)
    [196]=>
    float(0)
    [197]=>
    float(7.142)
    [198]=>
    float(0)
    [199]=>
    float(0)
    [200]=>
    float(28.571)
    [201]=>
    float(21.428)
    [202]=>
    float(14.285)
    [203]=>
    float(7.142)
    [204]=>
    float(0)
    [205]=>
    float(0)
    [206]=>
    float(0)
    [207]=>
    float(7.142)
    [208]=>
    float(0)
    [209]=>
    float(0)
    [210]=>
    float(35.714)
    [211]=>
    float(28.571)
    [212]=>
    float(21.428)
    [213]=>
    float(14.285)
    [214]=>
    float(7.142)
    [215]=>
    float(0)
    [216]=>
    float(42.857)
    [217]=>
    float(35.714)
    [218]=>
    float(28.571)
    [219]=>
    float(21.428)
    [220]=>
    float(14.285)
    [221]=>
    float(7.142)
    [222]=>
    float(0)
    [223]=>
    float(100)
    [224]=>
    float(100)
    [225]=>
    float(100)
    [226]=>
    float(92.857)
    [227]=>
    float(85.714)
    [228]=>
    float(78.571)
    [229]=>
    float(71.428)
    [230]=>
    float(64.285)
    [231]=>
    float(57.142)
    [232]=>
    float(100)
    [233]=>
    float(100)
    [234]=>
    float(100)
    [235]=>
    float(100)
    [236]=>
    float(100)
    [237]=>
    float(92.857)
  }
}
