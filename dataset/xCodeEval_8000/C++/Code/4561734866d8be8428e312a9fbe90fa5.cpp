#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int ch[100100][25] = {
	{123,2,154,721,1246,1356,1360,1568,1863,1953,1960,2031,2059,2063,-1},{4567,3,34,69,73,95,125,132,137,146,150,-1},{5478,4,11,17,23,29,30,33},{4689,5,6,7,8,9,10,-1},{815,-1,-1,-1,-1,-1},{814,-1,-1,-1},{915,-1,-1,-1,-1,-1},{184,-1,-1,-1},{125,-1,-1,-1},{124,-1,-1},{184,12,13,14,15,16},{759,-1,-1,-1,-1},{815,-1,-1,-1,-1},{712,-1,-1},{815,-1,-1,-1,-1},{712,-1,-1},{5648,18,19,20,21,-1,22,-1},{819,-1,-1,-1},{189,-1,-1,-1},{128,-1,-1},{186,-1,-1,-1},{148,-1,-1,-1},{879,24,25,26,27,-1,28},{184,-1,-1,-1},{714,-1,-1,-1,-1},{124,-1,-1},{149,-1,-1,-1,-1},{124,-1,-1},{617,-1,-1,-1,-1},{148,-1,31,-1,32,-1},{125,-1,-1},{125,-1,-1},{174,-1,-1,-1},{5678,35,41,49,50,55,62,65,66,67,68,-1},{146,36,37,38,39,40},{754,-1,-1,-1,-1},{154,-1,-1,-1,-1},{712,-1,-1},{145,-1,-1,-1,-1},{712,-1,-1},{846,42,43,44,45,46,47,-1,48,-1},{125,-1,-1},{124,-1,-1},{124,-1,-1},{712,-1,-1},{124,-1,-1},{154,-1,-1,-1},{125,-1,-1},{715,-1,-1,-1},{479,51,52,-1,53,54,-1},{145,-1,-1,-1},{125,-1,-1},{145,-1,-1,-1},{125,-1,-1},{458,56,57,58,-1,59,60,61},{175,-1,-1,-1},{172,-1,-1},{126,-1,-1,-1},{126,-1,-1},{126,-1,-1,-1},{126,-1,-1},{125,63,64},{126,-1,-1},{172,-1,-1},{574,-1,-1,-1,-1,-1},{684,-1,-1,-1,-1,-1,-1,-1,-1},{175,-1,-1,-1},{142,-1,-1,-1},{675,70,71,72},{146,-1,-1,-1},{456,-1,-1,-1},{145,-1,-1,-1},{4578,74,78,82,88,91,92,94},{864,75,76,-1,77,-1,-1},{691,-1,-1,-1},{127,-1,-1,-1},{125,-1,-1,-1},{841,79,80,81,-1,-1},{152,-1,-1},{182,-1,-1},{152,-1,-1},{4589,83,84,85,86,87},{712,-1,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{584,89,-1,90,-1,-1,-1},{125,-1,-1},{125,-1,-1},{124,-1,-1},{148,-1,-1,-1,93,-1},{125,-1,-1},{124,-1,-1},{4578,96,102,108,109,112,118,119,120,121,124},{164,97,98,99,100,101},{691,-1,-1,-1},{641,-1,-1,-1},{719,-1,-1,-1},{125,-1,-1,-1},{712,-1,-1,-1},{846,103,104,105,-1,106,107,-1},{152,-1,-1},{157,-1,-1,-1},{127,-1,-1,-1},{125,-1,-1},{127,-1,-1,-1},{451,-1,-1,-1},{546,110,-1,111,-1,-1,-1},{125,-1,-1},{124,-1,-1},{586,113,-1,114,115,116,-1,117,-1},{125,-1,-1},{124,-1,-1},{124,-1,-1},{125,-1,-1},{124,-1,-1},{124,-1,-1},{146,-1,-1,-1,-1},{549,-1,-1,-1,-1,-1,-1},{128,122,123},{124,-1,-1},{142,-1,-1},{124,-1,-1},{145,126,129},{124,127,128},{126,-1,-1},{162,-1,-1},{125,130,131},{126,-1,-1},{162,-1,-1},{4678,133,134,135,136,-1,-1},{186,-1,-1,-1},{812,-1,-1},{124,-1,-1},{186,-1,-1,-1},{468,138,139,140,141,142,143,144,145},{147,-1,-1,-1,-1},{541,-1,-1,-1,-1,-1},{125,-1,-1},{127,-1,-1},{518,-1,-1,-1,-1,-1},{124,-1,-1},{124,-1,-1},{127,-1,-1},{127,147,148},{164,-1,-1,-1},{142,149,-1},{152,-1,-1},{568,151,152,153,-1,-1},{125,-1,-1},{125,-1,-1},{124,-1,-1},{1456,155,178,333,470,506,510,561,637,670,674,704,712,715,-1},{2378,156,162,167,170,-1,176,177},{789,157,158,161},{1907,-1,-1,-1,-1},{182,159,160},{129,-1,-1},{127,-1,-1},{1029,-1,-1,-1},{289,163,164,165,166,-1,-1,-1},{891,-1,-1,-1},{712,-1,-1},{719,-1,-1,-1},{712,-1,-1,-1},{1908,168,169,-1,-1},{129,-1,-1},{128,-1,-1},{379,171,172,173,174,-1,175},{187,-1,-1,-1},{791,-1,-1,-1},{812,-1,-1,-1},{182,-1,-1},{172,-1,-1},{3708,-1,-1,-1,-1,-1,-1},{124,-1,-1},{4207,179,196,231,266,273,294,316,324,331,332},{3589,180,183,186,189,192,193,-1,-1},{132,181,182},{162,-1,-1},{612,-1,-1},{135,-1,184,185},{125,-1,-1},{812,-1,-1},{139,187,-1,188},{162,-1,-1},{612,-1,-1},{125,190,191},{128,-1,-1},{182,-1,-1},{162,-1,-1},{129,194,195},{125,-1,-1},{132,-1,-1},{1689,197,203,209,214,218,224,229,230,-1},{378,198,199,200,201,-1,202,-1},{791,-1,-1,-1},{712,-1,-1},{172,-1,-1},{518,-1,-1,-1},{125,-1,-1},{348,204,205,206,-1,207,-1,208,-1,-1},{512,-1,-1,-1},{1520,-1,-1,-1},{891,-1,-1,-1},{135,-1,-1,-1},{162,-1,-1},{718,210,211,212,-1,213,-1,-1,-1},{891,-1,-1,-1},{891,-1,-1,-1},{891,-1,-1,-1},{162,-1,-1},{138,215,216,217},{312,-1,-1},{312,-1,-1},{512,-1,-1},{3916,219,220,221,222,223,-1,-1},{135,-1,-1,-1},{124,-1,-1,-1},{361,-1,-1,-1},{135,-1,-1,-1},{124,-1,-1},{791,225,226,-1,227,-1,228,-1},{129,-1,-1},{129,-1,-1},{128,-1,-1},{129,-1,-1},{136,-1,-1,-1,-1},{139,-1,-1,-1},{765,232,236,242,248,253,254,259,264,265},{142,233,234,235},{182,-1,-1},{128,-1,-1},{812,-1,-1},{3748,237,238,239,240,241,-1,-1,-1},{182,-1,-1},{371,-1,-1,-1},{371,-1,-1,-1},{1820,-1,-1,-1},{124,-1,-1},{2875,-1,243,-1,244,245,-1,-1,246,247},{125,-1,-1},{612,-1,-1},{512,-1,-1,-1},{128,-1,-1,-1},{128,-1,-1},{1580,-1,249,-1,250,251,-1,252,-1,-1},{125,-1,-1},{691,-1,-1,-1},{612,-1,-1,-1},{175,-1,-1,-1},{834,-1,-1,-1,-1,-1,-1},{162,255,256,257,258},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{1085,260,261,-1,262,-1,263,-1,-1},{162,-1,-1},{125,-1,-1},{128,-1,-1},{172,-1,-1},{862,-1,-1,-1,-1,-1,-1},{128,-1,-1},{741,267,268,269,270,271,272},{128,-1,-1},{178,-1,-1,-1,-1},{148,-1,-1,-1,-1},{1028,-1,-1,-1,-1},{182,-1,-1,-1,-1},{128,-1,-1},{2637,274,277,282,285,289,290,291,292,293},{518,275,276,-1},{819,-1,-1,-1},{128,-1,-1},{125,278,279,280,281},{128,-1,-1},{128,-1,-1},{128,-1,-1},{182,-1,-1},{128,283,284},{162,-1,-1},{162,-1,-1},{126,286,287,288},{128,-1,-1},{812,-1,-1},{128,-1,-1},{318,-1,-1,-1,-1},{3068,-1,-1,-1,-1,-1,-1},{518,-1,-1,-1,-1},{138,-1,-1,-1,-1},{128,-1,-1},{567,295,299,304,307,311,312,313,314,315},{214,296,297,298},{182,-1,-1},{128,-1,-1},{182,-1,-1},{4018,300,301,302,303,-1,-1},{812,-1,-1},{132,-1,-1},{182,-1,-1},{132,-1,-1},{185,-1,305,-1,306,-1,-1},{125,-1,-1},{172,-1,-1},{768,-1,308,309,310,-1,-1,-1},{125,-1,-1},{125,-1,-1},{125,-1,-1},{318,-1,-1,-1,-1},{168,-1,-1,-1,-1},{687,-1,-1,-1,-1,-1,-1},{168,-1,-1,-1,-1},{128,-1,-1},{4278,317,318,-1,-1,319,320,321,322,323,-1},{714,-1,-1,-1},{714,-1,-1,-1,-1},{192,-1,-1,-1,-1},{124,-1,-1},{129,-1,-1},{134,-1,-1,-1},{172,-1,-1,-1},{3248,325,326,327,328,329,330,-1,-1},{915,-1,-1,-1,-1},{815,-1,-1,-1,-1},{137,-1,-1,-1},{132,-1,-1},{162,-1,-1,-1},{164,-1,-1,-1,-1},{4708,-1,-1,-1,-1,-1,-1,-1,-1},{183,-1,-1,-1,-1},{564,334,360,387,402,411,444,453,466},{4015,335,340,344,349,356},{6780,336,-1,337,338,339,-1},{172,-1,-1,-1},{182,-1,-1,-1},{172,-1,-1},{127,-1,-1},{785,341,342,-1,-1,343,-1},{812,-1,-1,-1},{147,-1,-1,-1},{147,-1,-1,-1},{6708,345,-1,346,347,348,-1},{127,-1,-1,-1},{128,-1,-1,-1},{127,-1,-1},{127,-1,-1},{714,350,351,352,353,354,355},{182,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{748,357,358,-1,-1,359,-1},{812,-1,-1,-1},{127,-1,-1,-1},{128,-1,-1,-1},{2678,361,364,370,374,375,376,383,384,385,386},{149,362,363,-1},{132,-1,-1},{312,-1,-1},{375,365,366,367,368,369,-1},{129,-1,-1},{142,-1,-1,-1},{134,-1,-1,-1},{135,-1,-1,-1},{142,-1,-1,-1},{2485,-1,371,372,-1,-1,373,-1,-1,-1,-1},{129,-1,-1},{127,-1,-1},{124,-1,-1},{147,-1,-1,-1,-1},{3965,-1,-1,-1,-1,-1,-1,-1,-1},{247,377,378,-1,379,380,381,382},{132,-1,-1},{134,-1,-1,-1},{124,-1,-1},{125,-1,-1,-1},{142,-1,-1},{124,-1,-1},{148,-1,-1,-1,-1,-1,-1},{348,-1,-1,-1,-1,-1,-1},{147,-1,-1,-1,-1},{124,-1,-1},{4078,388,389,394,-1,398,399,400,401,-1},{1905,-1,-1,-1,-1},{175,390,391,-1,392,393},{612,-1,-1},{124,-1,-1},{612,-1,-1},{612,-1,-1},{612,395,396,397},{127,-1,-1},{127,-1,-1},{127,-1,-1},{4609,-1,-1,-1,-1,-1,-1,-1,-1,-1},{4507,-1,-1,-1,-1,-1,-1,-1,-1},{124,-1,-1},{548,-1,-1,-1,-1,-1},{5714,403,404,405,406,407,408,409,410},{812,-1,-1},{185,-1,-1,-1,-1},{178,-1,-1,-1,-1},{158,-1,-1,-1,-1},{187,-1,-1,-1,-1},{812,-1,-1},{128,-1,-1},{128,-1,-1},{367,412,413,419,424,425,431,437,438,-1,443},{2548,-1,-1,-1,-1,-1,-1,-1,-1},{268,414,415,416,417,418,-1,-1},{134,-1,-1,-1},{142,-1,-1,-1},{124,-1,-1},{124,-1,-1},{134,-1,-1,-1},{2684,-1,420,-1,-1,421,422,-1,423},{124,-1,-1},{124,-1,-1},{132,-1,-1},{124,-1,-1},{671,-1,-1,-1},{268,-1,426,427,428,429,-1,430},{124,-1,-1},{125,-1,-1,-1},{125,-1,-1,-1},{125,-1,-1,-1},{124,-1,-1},{257,432,433,434,435,436,-1},{128,-1,-1},{128,-1,-1},{124,-1,-1},{125,-1,-1},{132,-1,-1},{125,-1,-1,-1},{248,439,440,441,442},{125,-1,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{4067,445,446,447,448,449,-1,450,451,-1,452,-1},{4580,-1,-1,-1,-1,-1,-1,-1,-1},{1608,-1,-1,-1,-1,-1,-1,-1},{612,-1,-1},{4580,-1,-1,-1,-1,-1,-1,-1,-1},{4587,-1,-1,-1,-1,-1,-1},{185,-1,-1,-1,-1},{468,-1,-1,-1,-1},{148,-1,-1,-1},{265,454,457,458,461,462,465},{137,455,-1,456,-1},{128,-1,-1},{128,-1,-1},{178,-1,-1,-1},{317,459,-1,460,-1},{128,-1,-1},{128,-1,-1},{2748,-1,-1,-1,-1,-1,-1},{172,463,-1,464,-1},{128,-1,-1},{128,-1,-1},{7018,-1,-1,-1},{1067,467,-1,468,-1,469,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{2571,471,477,484,485,491,498,499,504,505},{3618,472,473,474,475,-1,476,-1,-1},{145,-1,-1,-1},{145,-1,-1,-1},{1204,-1,-1,-1},{124,-1,-1,-1},{124,-1,-1,-1},{4285,478,479,480,481,482,-1,-1,483,-1},{614,-1,-1,-1},{124,-1,-1},{124,-1,-1},{614,-1,-1,-1},{612,-1,-1},{126,-1,-1},{745,-1,-1,-1,-1,-1},{4381,486,487,-1,488,489,490,-1,-1},{124,-1,-1},{132,-1,-1},{612,-1,-1},{612,-1,-1},{162,-1,-1},{781,492,493,494,495,496,497},{145,-1,-1,-1},{124,-1,-1,-1},{124,-1,-1,-1},{162,-1,-1,-1},{145,-1,-1,-1},{142,-1,-1,-1},{214,-1,-1,-1,-1,-1},{4285,500,501,502,-1,503,-1},{162,-1,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{162,-1,-1,-1},{124,-1,-1},{521,507,508,509},{124,-1,-1},{124,-1,-1},{142,-1,-1},{2054,511,523,533,540,548,557},{376,512,515,516,519,520,521,522},{127,513,514},{128,-1,-1},{182,-1,-1},{128,-1,-1},{132,517,518},{182,-1,-1},{812,-1,-1},{3708,-1,-1,-1,-1,-1,-1},{182,-1,-1},{178,-1,-1,-1,-1},{128,-1,-1},{267,524,527,528,529,530,531,532},{128,525,526},{132,-1,-1},{132,-1,-1},{138,-1,-1,-1,-1},{812,-1,-1},{718,-1,-1,-1,-1},{138,-1,-1,-1,-1},{182,-1,-1},{178,-1,-1,-1,-1},{1370,534,535,536,537,538,539},{182,-1,-1},{138,-1,-1,-1,-1},{187,-1,-1,-1,-1},{183,-1,-1,-1,-1},{128,-1,-1},{128,-1,-1},{375,541,542,543,544,545,546,547},{182,-1,-1},{183,-1,-1,-1,-1},{158,-1,-1,-1,-1},{187,-1,-1,-1,-1},{128,-1,-1},{158,-1,-1,-1,-1},{187,-1,-1,-1,-1},{1752,549,550,551,552,553,554,555,556},{128,-1,-1},{178,-1,-1,-1,-1},{812,-1,-1},{178,-1,-1,-1,-1},{187,-1,-1,-1,-1},{812,-1,-1,-1,-1},{128,-1,-1},{128,-1,-1},{1728,558,559,-1,-1,560,-1},{127,-1,-1,-1},{129,-1,-1,-1},{129,-1,-1,-1},{1276,562,569,582,589,590,610,622,628,635,636},{489,563,564,565,566,567,568},{318,-1,-1,-1,-1,-1},{1028,-1,-1,-1,-1,-1},{195,-1,-1,-1,-1,-1},{485,-1,-1,-1,-1,-1},{125,-1,-1},{128,-1,-1},{254,570,575,576,577,578,579,580,581},{189,571,572,573,574},{132,-1,-1},{128,-1,-1},{132,-1,-1},{129,-1,-1},{5860,-1,-1,-1,-1,-1,-1,-1,-1},{785,-1,-1,-1,-1,-1,-1},{3806,-1,-1,-1,-1,-1,-1},{1680,-1,-1,-1,-1,-1,-1,-1},{187,-1,-1,-1,-1},{312,-1,-1},{178,-1,-1,-1},{356,583,584,585,586,587,588,-1},{817,-1,-1,-1,-1,-1,-1},{2068,-1,-1,-1,-1,-1,-1},{162,-1,-1,-1,-1},{2748,-1,-1,-1,-1,-1,-1},{2608,-1,-1,-1,-1,-1,-1},{1620,-1,-1,-1,-1},{647,-1,-1,-1,-1,-1},{546,591,592,-1,593,594,599,604,609},{184,-1,-1,-1,-1},{284,-1,-1,-1,-1,-1},{148,-1,-1,-1,-1},{134,595,596,597,598},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{894,600,601,602,603},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{148,605,606,607,608},{132,-1,-1},{132,-1,-1},{312,-1,-1},{312,-1,-1},{148,-1,-1,-1,-1},{247,611,615,616,617,618,619,620,621,-1},{819,612,613,614},{162,-1,-1},{126,-1,-1},{126,-1,-1},{1587,-1,-1,-1,-1,-1,-1},{1748,-1,-1,-1,-1,-1,-1,-1},{275,-1,-1,-1,-1},{138,-1,-1,-1,-1},{738,-1,-1,-1,-1,-1,-1},{124,-1,-1},{128,-1,-1},{718,623,624,625,-1,626,-1,-1,627},{124,-1,-1},{162,-1,-1},{162,-1,-1},{126,-1,-1},{126,-1,-1},{286,629,630,631,632,633,-1,634},{125,-1,-1,-1},{125,-1,-1,-1},{314,-1,-1,-1},{124,-1,-1},{142,-1,-1,-1},{124,-1,-1},{148,-1,-1,-1,-1},{124,-1,-1},{1758,638,644,649,650,655,661,668,669},{536,639,640,641,-1,-1,642,-1,643,-1},{261,-1,-1,-1},{125,-1,-1},{125,-1,-1,-1},{125,-1,-1,-1},{124,-1,-1},{461,645,-1,646,-1,-1,647,648},{512,-1,-1},{125,-1,-1},{127,-1,-1},{127,-1,-1},{4517,-1,-1,-1,-1,-1,-1,-1,-1},{254,-1,651,652,653,654,-1},{162,-1,-1},{132,-1,-1},{312,-1,-1},{134,-1,-1},{594,656,657,658,659,660,-1,-1},{127,-1,-1,-1},{621,-1,-1,-1},{125,-1,-1},{167,-1,-1,-1},{125,-1,-1},{1067,662,663,664,665,666,-1,667,-1},{128,-1,-1},{612,-1,-1},{126,-1,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{754,-1,-1,-1,-1,-1,-1},{465,671,672,673},{126,-1,-1},{124,-1,-1},{125,-1,-1},{2435,675,679,684,688,693,697,700,703},{172,676,677,678},{182,-1,-1},{128,-1,-1},{128,-1,-1},{267,680,681,682,-1,683},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{7308,-1,685,686,687,-1,-1},{124,-1,-1},{127,-1,-1},{124,-1,-1},{267,689,690,691,-1,692},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{276,694,-1,695,696,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{127,698,699,-1,-1},{128,-1,-1},{128,-1,-1},{137,701,-1,702,-1},{128,-1,-1},{128,-1,-1},{178,-1,-1,-1},{7158,705,706,707,708,709,710,711},{465,-1,-1,-1,-1,-1},{417,-1,-1,-1,-1,-1,-1},{174,-1,-1,-1,-1},{316,-1,-1,-1,-1,-1},{415,-1,-1,-1,-1,-1},{184,-1,-1,-1,-1},{124,-1,-1},{412,713,714,-1},{124,-1,-1},{125,-1,-1},{1478,716,717,718,719,720},{129,-1,-1,-1},{127,-1,-1},{125,-1,-1},{125,-1,-1},{125,-1,-1},{1204,722,855,986,1020,1063,1142,1185,1223,1237},{2350,723,745,772,788,795,821,834,845,850},{631,724,728,729,733,737,741,744},{127,725,726,727},{128,-1,-1},{128,-1,-1},{128,-1,-1},{718,-1,-1,-1},{172,730,731,732},{182,-1,-1},{128,-1,-1},{128,-1,-1},{167,734,735,736},{128,-1,-1},{128,-1,-1},{127,-1,-1},{712,738,739,740},{812,-1,-1},{128,-1,-1},{128,-1,-1},{137,742,-1,743,-1},{128,-1,-1},{128,-1,-1},{7018,-1,-1,-1},{135,746,750,754,758,762,766},{671,747,748,-1,749,-1},{182,-1,-1},{168,-1,-1,-1,-1},{178,-1,-1,-1,-1},{167,751,752,-1,753,-1},{128,-1,-1},{168,-1,-1,-1,-1},{168,-1,-1,-1,-1},{617,755,756,757,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{6701,759,760,-1,761,-1},{812,-1,-1},{618,-1,-1,-1,-1},{718,-1,-1,-1,-1},{6017,763,764,-1,765,-1},{128,-1,-1},{168,-1,-1,-1,-1},{178,-1,-1,-1,-1},{6537,767,768,769,770,771,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{5031,773,775,778,780,783,786},{167,774,-1,-1},{128,-1,-1},{167,776,777},{128,-1,-1},{126,-1,-1},{167,779,-1,-1},{128,-1,-1},{167,781,782},{128,-1,-1},{126,-1,-1},{167,784,785},{128,-1,-1},{126,-1,-1},{167,787,-1,-1},{128,-1,-1},{6718,789,790,791,792,793,794,-1},{9067,-1,-1,-1,-1,-1},{7018,-1,-1,-1,-1},{719,-1,-1,-1,-1,-1},{217,-1,-1,-1,-1,-1},{126,-1,-1},{126,-1,-1},{135,796,800,804,810,814,818},{6071,797,798,-1,799,-1},{182,-1,-1},{168,-1,-1,-1,-1},{178,-1,-1,-1,-1},{671,801,802,-1,803,-1},{182,-1,-1},{168,-1,-1,-1,-1},{178,-1,-1,-1,-1},{3671,805,806,807,-1,808,809,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{128,-1,-1},{152,-1,-1},{617,811,812,-1,813,-1},{128,-1,-1},{168,-1,-1,-1,-1},{178,-1,-1,-1,-1},{6701,815,816,-1,817,-1},{812,-1,-1},{618,-1,-1,-1,-1},{718,-1,-1,-1,-1},{167,819,820},{128,-1,-1},{126,-1,-1},{2536,822,823,826,827,830,831,832,-1,833,-1},{178,-1,-1,-1},{157,824,-1,825,-1},{128,-1,-1},{128,-1,-1},{152,-1,-1},{137,828,-1,829,-1},{128,-1,-1},{128,-1,-1},{1036,-1,-1,-1},{7018,-1,-1,-1},{768,-1,-1,-1,-1},{178,-1,-1,-1},{2067,835,836,837,-1,841,842,843,844,-1},{128,-1,-1},{286,-1,-1,-1,-1},{172,838,839,840},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{168,-1,-1,-1,-1,-1,-1},{126,-1,-1},{168,-1,-1,-1,-1},{2365,846,-1,847,848,-1,-1,849,-1},{718,-1,-1,-1},{178,-1,-1,-1},{7018,-1,-1,-1},{178,-1,-1,-1},{1670,851,852,853,854},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{2051,856,878,900,907,922,948,956,969,982},{346,857,862,866,867,871,875,876,877,-1},{3417,858,-1,859,-1,860,-1,861,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{3407,-1,863,-1,-1,864,-1,-1,865,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{461,-1,-1,-1},{317,868,-1,869,-1,870,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{357,872,873,-1,-1,874,-1},{126,-1,-1},{128,-1,-1},{128,-1,-1},{142,-1,-1},{7018,-1,-1,-1},{7018,-1,-1,-1,-1,-1},{162,879,883,887,890,893,897},{234,880,881,882},{312,-1,-1},{312,-1,-1},{412,-1,-1},{712,884,885,886},{812,-1,-1},{128,-1,-1},{128,-1,-1},{617,888,-1,889,-1},{128,-1,-1},{128,-1,-1},{132,891,892},{312,-1,-1},{412,-1,-1},{712,894,895,896},{812,-1,-1},{128,-1,-1},{128,-1,-1},{617,898,-1,899,-1},{128,-1,-1},{128,-1,-1},{5670,901,902,903,904,905,906,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{138,-1,-1,-1},{126,-1,-1},{138,-1,-1,-1},{1346,908,909,913,914,915,919,920,921,-1,-1},{478,-1,-1,-1,-1,-1,-1},{3407,910,-1,911,-1,912,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{461,-1,-1,-1},{178,-1,-1,-1},{367,916,917,-1,918,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{142,-1,-1},{178,-1,-1,-1},{7018,-1,-1,-1,-1},{216,923,928,935,940,944,945},{342,924,925,-1,926,-1,927},{412,-1,-1},{134,-1,-1,-1},{135,-1,-1,-1},{125,-1,-1},{1072,929,930,931,932,933,934},{182,-1,-1},{128,-1,-1},{128,-1,-1},{182,-1,-1},{128,-1,-1},{128,-1,-1},{2760,936,-1,937,-1,938,-1,939,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{1728,941,942,-1,-1,943,-1},{127,-1,-1,-1},{129,-1,-1,-1},{129,-1,-1,-1},{678,-1,-1,-1,-1,-1,-1},{713,946,947,-1,-1},{128,-1,-1},{128,-1,-1},{6715,949,950,951,952,953,954,955},{182,-1,-1,-1,-1},{162,-1,-1,-1,-1},{138,-1,-1,-1,-1},{136,-1,-1,-1,-1},{813,-1,-1,-1,-1},{126,-1,-1},{126,-1,-1},{671,957,958,-1,962,963,964,-1,967,968,-1,-1},{128,-1,-1},{126,959,960,961},{128,-1,-1},{128,-1,-1},{128,-1,-1},{382,-1,-1,-1,-1},{781,-1,-1,-1,-1,-1,-1,-1,-1},{168,965,966,-1,-1,-1,-1},{126,-1,-1},{126,-1,-1},{178,-1,-1,-1,-1},{128,-1,-1},{2305,970,972,975,977,980},{167,971,-1,-1},{128,-1,-1},{167,973,974},{128,-1,-1},{126,-1,-1},{167,976,-1,-1},{128,-1,-1},{167,978,979},{128,-1,-1},{126,-1,-1},{167,981,-1,-1},{128,-1,-1},{631,983,-1,984,985,-1,-1},{178,-1,-1,-1},{718,-1,-1,-1},{7018,-1,-1,-1},{2560,987,993,1000,1001,1007,1013,1014,1018,1019},{4013,988,989,990,991,992},{7018,-1,-1,-1},{7018,-1,-1,-1},{718,-1,-1,-1},{178,-1,-1,-1},{178,-1,-1,-1},{4517,994,995,-1,996,997,998,999,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{132,-1,-1},{126,-1,-1},{145,-1,-1,-1},{413,1002,1003,1004,1005,1006},{718,-1,-1,-1},{178,-1,-1,-1},{718,-1,-1,-1},{178,-1,-1,-1},{7018,-1,-1,-1},{4716,1008,1009,-1,1010,1011,-1,1012},{128,-1,-1},{125,-1,-1},{125,-1,-1},{162,-1,-1},{126,-1,-1},{126,-1,-1,-1},{247,1015,1016,-1,-1,1017,-1},{125,-1,-1},{128,-1,-1},{128,-1,-1},{125,-1,-1},{125,-1,-1},{256,1021,1026,1035,1041,1042,1050,1057,1058,-1,-1},{378,1022,-1,1023,1024,1025,-1},{127,-1,-1,-1},{128,-1,-1,-1},{127,-1,-1},{127,-1,-1},{367,1027,1028,1029,1030,1031,1032,1033,1034,-1},{185,-1,-1,-1,-1},{189,-1,-1,-1,-1,-1},{128,-1,-1},{128,-1,-1},{138,-1,-1,-1,-1},{287,-1,-1,-1,-1,-1},{128,-1,-1},{128,-1,-1},{1367,1036,1037,1038,1039,1040,-1,-1,-1},{185,-1,-1,-1,-1},{158,-1,-1,-1},{185,-1,-1,-1,-1},{358,-1,-1,-1,-1},{125,-1,-1},{312,-1,-1},{237,1043,-1,1044,1045,1046,1047,1048,1049},{158,-1,-1,-1,-1},{128,-1,-1},{187,-1,-1,-1,-1},{128,-1,-1},{128,-1,-1},{138,-1,-1,-1,-1},{128,-1,-1},{637,1051,1052,1053,1054,1055,1056,-1,-1,-1},{128,-1,-1},{158,-1,-1,-1},{318,-1,-1,-1,-1},{312,-1,-1},{185,-1,-1,-1,-1},{158,-1,-1,-1,-1},{361,-1,-1,-1,-1},{1736,1059,-1,1060,-1,1061,1062},{128,-1,-1},{128,-1,-1},{128,-1,-1},{125,-1,-1},{1562,1064,1069,1079,1096,1102,1103,1111,1122,-1,1127,1134,-1,1138,-1},{3074,1065,-1,1066,-1,1067,-1,1068,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{1734,1070,1073,1074,-1,1075,1076,1077,-1,1078,-1,-1},{189,1071,1072},{128,-1,-1},{129,-1,-1},{8270,-1,-1,-1,-1,-1,-1,-1,-1},{3548,-1,-1,-1,-1,-1,-1,-1,-1},{128,-1,-1},{2348,-1,-1,-1,-1,-1,-1,-1},{318,-1,-1,-1,-1,-1,-1},{815,-1,-1,-1,-1},{275,1080,1081,1082,1087,1088,1092,1093,1094,1095,-1,-1},{312,-1,-1},{638,-1,-1,-1,-1,-1,-1},{326,1083,1084,1085,-1,1086},{128,-1,-1},{612,-1,-1},{128,-1,-1},{128,-1,-1},{126,-1,-1,-1},{189,1089,1090,1091},{132,-1,-1},{128,-1,-1},{129,-1,-1},{2817,-1,-1,-1,-1,-1,-1,-1,-1},{258,-1,-1,-1,-1,-1,-1},{125,-1,-1},{348,-1,-1,-1,-1},{2517,1097,1098,1099,1100,1101,-1,-1,-1},{158,-1,-1,-1,-1},{158,-1,-1,-1,-1,-1},{152,-1,-1},{286,-1,-1,-1,-1,-1},{185,-1,-1,-1,-1,-1},{215,-1,-1,-1},{782,1104,1105,1106,1107,1108,1109,-1,1110,-1},{132,-1,-1},{237,-1,-1,-1,-1,-1},{1027,-1,-1,-1,-1,-1},{128,-1,-1},{179,-1,-1,-1},{812,-1,-1,-1,-1},{128,-1,-1},{1057,-1,1112,1113,1114,-1,1115,1116,1117,1118,1119,1120,1121,-1},{682,-1,-1,-1,-1,-1,-1,-1},{6782,-1,-1,-1,-1,-1,-1,-1,-1},{138,-1,-1,-1},{132,-1,-1},{368,-1,-1,-1,-1},{125,-1,-1},{128,-1,-1},{158,-1,-1,-1,-1,-1},{125,-1,-1},{128,-1,-1},{571,1123,1124,1125,1126,-1},{132,-1,-1},{126,-1,-1},{128,-1,-1},{125,-1,-1},{2578,1128,1129,1130,-1,1131,1132,1133,-1},{129,-1,-1},{127,-1,-1,-1},{182,-1,-1,-1},{125,-1,-1},{135,-1,-1,-1},{172,-1,-1,-1},{157,1135,1136,-1,1137,-1},{128,-1,-1},{125,-1,-1},{128,-1,-1},{167,1139,-1,1140,1141},{128,-1,-1},{128,-1,-1},{125,-1,-1},{1452,1143,1157,1162,1163,1171,-1,1175,1179,-1,1182,-1},{2043,1144,1147,1149,1152,1155},{167,1145,1146},{128,-1,-1},{126,-1,-1},{167,1148,-1,-1},{128,-1,-1},{167,1150,1151},{128,-1,-1},{126,-1,-1},{167,1153,1154},{128,-1,-1},{126,-1,-1},{167,1156,-1,-1},{128,-1,-1},{6241,-1,1158,-1,-1,1159,-1,-1,1160,-1,1161,-1},{718,-1,-1,-1},{178,-1,-1,-1},{178,-1,-1,-1},{7018,-1,-1,-1},{231,-1,-1,-1},{1647,1164,1165,1166,1167,1168,1169,1170},{182,-1,-1,-1,-1},{186,-1,-1,-1,-1},{126,-1,-1},{126,-1,-1},{1028,-1,-1,-1,-1},{126,-1,-1},{126,-1,-1},{235,1172,1173,-1,1174},{142,-1,-1},{124,-1,-1},{125,-1,-1},{1067,1176,1177,1178,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{467,1180,1181,-1},{128,-1,-1},{126,-1,-1},{167,1183,1184,-1},{128,-1,-1},{125,-1,-1},{256,1186,1189,1195,-1,1201,1207,1214,-1,1219,1222,-1,-1},{137,1187,-1,1188,-1},{128,-1,-1},{128,-1,-1},{1758,1190,1191,1192,1193,-1,1194,-1},{312,-1,-1},{317,-1,-1,-1},{136,-1,-1,-1},{127,-1,-1,-1},{127,-1,-1},{1578,1196,-1,1197,1198,1199,1200,-1,-1},{312,-1,-1},{124,-1,-1},{125,-1,-1},{127,-1,-1},{125,-1,-1},{3247,-1,1202,1203,1204,-1,1205,1206,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{1067,-1,1208,1209,1210,1211,1212,-1,1213,-1},{128,-1,-1,-1},{128,-1,-1},{128,-1,-1,-1},{178,-1,-1,-1},{128,-1,-1},{128,-1,-1},{175,1215,1216,1217,1218,-1},{128,-1,-1},{158,-1,-1,-1},{126,-1,-1},{168,-1,-1,-1},{157,1220,-1,-1,1221,-1},{128,-1,-1},{128,-1,-1},{7018,-1,-1,-1},{1456,1224,1227,1230,1231,1234,1235,1236,-1},{174,1225,-1,1226,-1},{128,-1,-1},{128,-1,-1},{217,1228,-1,1229,-1},{125,-1,-1},{128,-1,-1},{125,-1,-1},{147,-1,1232,-1,1233,-1},{128,-1,-1},{128,-1,-1},{124,-1,-1},{178,-1,-1,-1},{125,-1,-1,-1},{253,1238,-1,1241,1243,-1,-1},{167,1239,1240},{128,-1,-1},{126,-1,-1},{167,1242,-1,-1},{128,-1,-1},{167,1244,1245},{128,-1,-1},{126,-1,-1},{1045,1247,1274,1297,1305,1314,1340,1346,1350,1355},{2306,1248,1253,1256,1257,1258,1263,1264,1268,1272,1273,-1},{3712,1249,-1,1250,-1,1251,-1,1252,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{237,-1,-1,1254,-1,-1,1255,-1},{128,-1,-1},{128,-1,-1},{132,-1,-1},{7812,-1,-1,-1,-1,-1,-1},{3072,-1,1259,-1,1260,1261,-1,1262,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{128,-1,-1},{134,-1,-1},{178,1265,1266,1267},{129,-1,-1},{127,-1,-1},{127,-1,-1},{372,-1,1269,1270,1271},{128,-1,-1},{128,-1,-1},{132,-1,-1},{312,-1,-1,-1},{278,-1,-1,-1,-1},{2346,1275,1280,1283,1284,1289,1294,1295,1296},{2701,1276,1277,-1,-1,1278,1279,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{235,1281,-1,-1,1282,-1,-1,-1,-1},{213,-1,-1},{213,-1,-1},{235,-1,-1,-1,-1,-1,-1},{2701,1285,-1,1286,1287,-1,-1,1288,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{136,1290,1291,1292,1293},{213,-1,-1},{213,-1,-1},{213,-1,-1},{231,-1,-1},{234,-1,-1,-1,-1},{231,-1,-1},{213,-1,-1},{2401,1298,1299,-1,1300,1301,1302,1303,1304,-1},{312,-1,-1},{125,-1,-1},{125,-1,-1},{312,-1,-1},{125,-1,-1},{231,-1,-1},{125,-1,-1},{1637,1306,1307,1308,1309,1310,1311,1312,1313},{128,-1,-1},{126,-1,-1},{182,-1,-1,-1,-1},{286,-1,-1,-1,-1,-1},{126,-1,-1},{278,-1,-1,-1,-1,-1},{126,-1,-1},{126,-1,-1},{1607,1315,1319,1325,1330,1331,1335,1336,1338,1339},{234,-1,1316,-1,-1,1317,1318,-1},{124,-1,-1},{124,-1,-1},{132,-1,-1},{2018,1320,1321,-1,1322,1323,1324,-1},{132,-1,-1},{132,-1,-1},{132,-1,-1},{132,-1,-1},{124,-1,-1},{261,1326,1327,1328,1329,-1,-1},{124,-1,-1},{126,-1,-1},{132,-1,-1},{124,-1,-1},{235,-1,-1,-1,-1,-1,-1},{134,1332,1333,1334},{128,-1,-1},{128,-1,-1},{128,-1,-1},{317,-1,-1,-1,-1,-1,-1,-1},{128,-1,1337,-1,-1,-1},{129,-1,-1},{276,-1,-1,-1,-1},{126,-1,-1,-1},{1204,1341,1342,-1,1343,1344,-1,1345,-1,-1,-1},{132,-1,-1},{156,-1,-1,-1},{132,-1,-1},{124,-1,-1},{132,-1,-1},{637,1347,1348,-1,1349,-1,-1},{128,-1,-1,-1},{126,-1,-1,-1},{138,-1,-1,-1},{251,1351,1352,-1,-1,1353,1354},{124,-1,-1},{213,-1,-1},{213,-1,-1},{125,-1,-1},{124,-1,-1},{231,1357,1358,1359},{1304,-1,-1,-1},{1234,-1,-1,-1},{1240,-1,-1,-1},{145,1361,1382,1430,1443,1476,1522,1531,1558,1563},{2673,1362,1366,1371,1375,1379,1380,1381},{718,1363,1364,-1,1365,-1},{819,-1,-1,-1},{819,-1,-1,-1},{128,-1,-1},{186,1367,1368,1369,1370},{127,-1,-1},{127,-1,-1},{712,-1,-1},{712,-1,-1},{2896,1372,1373,1374,-1,-1,-1,-1},{712,-1,-1},{162,-1,-1},{128,-1,-1},{783,1376,1377,-1,-1,1378,-1,-1},{127,-1,-1},{127,-1,-1},{162,-1,-1},{896,-1,-1,-1,-1},{178,-1,-1,-1,-1},{128,-1,-1},{426,1383,1391,1398,1401,1407,1416,1420,1426,1429},{571,1384,1387,1388,1389,1390},{152,1385,1386},{182,-1,-1},{812,-1,-1},{5708,-1,-1,-1,-1,-1,-1},{182,-1,-1},{178,-1,-1,-1,-1},{128,-1,-1},{5678,1392,1393,1394,-1,1395,1396,-1,-1,-1},{182,-1,-1,-1},{561,-1,-1,-1,-1},{567,-1,-1,-1,-1,-1},{152,-1,-1,-1},{157,-1,1397,-1,-1},{162,-1,-1},{167,1399,-1,1400,-1},{128,-1,-1},{128,-1,-1},{7528,1402,-1,-1,-1,1403,-1,1404,1405,1406,-1},{182,-1,-1,-1},{127,-1,-1,-1},{128,-1,-1,-1},{127,-1,-1},{127,-1,-1},{724,1408,1409,1410,1411,1412,1413,1414,1415},{168,-1,-1,-1,-1},{162,-1,-1},{518,-1,-1,-1,-1},{548,-1,-1,-1,-1},{128,-1,-1},{812,-1,-1},{184,-1,-1,-1,-1},{128,-1,-1},{4607,1417,-1,1418,-1,1419,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{567,1421,1422,1423,-1,1424,1425,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{176,1427,-1,1428,-1},{128,-1,-1},{128,-1,-1},{7018,-1,-1,-1},{4526,1431,1434,1435,1436,-1,1439,1440,1441,1442,-1},{157,1432,-1,1433,-1},{128,-1,-1},{128,-1,-1},{152,-1,-1},{718,-1,-1,-1},{274,-1,1437,-1,1438,-1},{128,-1,-1},{128,-1,-1},{178,-1,-1,-1},{7028,-1,-1,-1,-1},{124,-1,-1},{178,-1,-1,-1},{617,1444,1445,1452,1458,1462,1463,1468,1473,1474,1475},{812,-1,-1,-1,-1},{725,1446,1447,1448,1449,1450,1451},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{168,1453,1454,1455,1456,1457,-1},{124,-1,-1},{172,-1,-1},{189,-1,-1,-1},{172,-1,-1},{128,-1,-1},{178,1459,-1,1460,1461,-1},{126,-1,-1},{126,-1,-1},{126,-1,-1},{128,-1,-1,-1,-1},{689,-1,1464,-1,1465,1466,-1,1467,-1},{124,-1,-1},{172,-1,-1},{126,-1,-1},{126,-1,-1},{278,1469,1470,1471,-1,-1,1472},{162,-1,-1},{162,-1,-1},{126,-1,-1},{126,-1,-1},{186,-1,-1,-1,-1},{178,-1,-1,-1,-1},{128,-1,-1},{256,1477,1482,1489,1494,1495,1503,1511,1512,1518,1521},{4078,1478,-1,1479,1480,1481,-1},{182,-1,-1,-1},{127,-1,-1,-1},{124,-1,-1},{127,-1,-1},{1768,1483,1484,1485,1486,-1,1487,1488,-1},{512,-1,-1},{517,-1,-1,-1},{157,-1,-1,-1,-1},{127,-1,-1,-1},{124,-1,-1,-1},{157,-1,-1,-1,-1},{427,1490,1491,-1,1492,-1,1493,-1},{128,-1,-1},{512,-1,-1},{128,-1,-1},{128,-1,-1},{412,-1,-1},{417,1496,1497,-1,1498,1499,1500,1501,1502},{128,-1,-1},{148,-1,-1,-1,-1},{184,-1,-1,-1,-1},{178,-1,-1,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{467,1504,-1,1505,1506,1507,-1,1508,1509,-1,1510,-1},{158,-1,-1,-1,-1},{128,-1,-1},{158,-1,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{178,-1,-1,-1},{467,1513,-1,1514,1515,1516,1517,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{157,1519,-1,1520,-1},{128,-1,-1},{128,-1,-1},{718,-1,-1,-1},{657,1523,1524,1525,1526,1527,1528,1529,1530},{128,-1,-1},{126,-1,-1},{184,-1,-1,-1,-1},{586,-1,-1,-1,-1,-1},{126,-1,-1},{284,-1,-1,-1,-1,-1},{124,-1,-1},{124,-1,-1},{256,1532,1536,1541,1544,1549,1554,1557},{127,1533,1534,1535},{128,-1,-1},{128,-1,-1},{128,-1,-1},{175,1537,-1,1538,1539,1540},{128,-1,-1},{182,-1,-1},{128,-1,-1},{128,-1,-1},{167,1542,-1,1543,-1},{128,-1,-1},{128,-1,-1},{217,1545,-1,1546,1547,1548},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{175,1550,-1,1551,1552,1553},{128,-1,-1},{182,-1,-1},{128,-1,-1},{128,-1,-1},{167,1555,-1,1556,-1},{128,-1,-1},{128,-1,-1},{718,-1,-1,-1},{465,1559,-1,1560,1561,-1,-1,1562,-1},{178,-1,-1,-1},{178,-1,-1,-1},{178,-1,-1,-1},{178,-1,-1,-1},{267,1564,1565,1566,1567},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{145,1569,1594,1650,1694,1699,1745,1796,1821,1824,1852,1859,1862},{6728,1570,1576,1580,1586,1591,1592,1593},{2670,1571,1572,1573,1574,1575},{182,-1,-1},{126,-1,-1},{182,-1,-1},{126,-1,-1},{126,-1,-1},{261,-1,1577,1578,-1,1579},{127,-1,-1},{172,-1,-1},{127,-1,-1},{369,1581,1582,1583,1584,1585},{124,-1,-1},{124,-1,-1},{127,-1,-1},{126,-1,-1},{127,-1,-1},{328,1587,1588,-1,1589,-1,1590},{162,-1,-1},{126,-1,-1},{126,-1,-1},{126,-1,-1},{318,-1,-1,-1,-1},{317,-1,-1,-1,-1},{126,-1,-1},{627,1595,1598,1607,1614,1615,1625,1636,1642,1643,1648,1649,-1},{213,1596,1597},{182,-1,-1},{812,-1,-1},{285,1599,1602,1603,-1,1604,1605,1606,-1,-1},{216,1600,-1,1601,-1},{172,-1,-1},{712,-1,-1},{713,-1,-1,-1,-1,-1,-1},{1903,-1,-1,-1,-1,-1},{124,-1,-1},{193,-1,-1,-1,-1},{152,-1,-1},{789,1608,1609,1610,1611,1612,-1,1613},{251,-1,-1,-1,-1,-1},{251,-1,-1,-1,-1,-1},{1068,-1,-1,-1,-1,-1},{1078,-1,-1,-1,-1,-1},{162,-1,-1,-1},{182,-1,-1,-1},{1062,-1,-1,-1},{324,1616,1617,1620,1621,1622,1623,1624},{218,-1,-1,-1,-1},{231,1618,1619},{128,-1,-1},{812,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{184,-1,-1,-1,-1},{128,-1,-1},{1326,1626,1627,1628,1631,1632,1633,1634,1635},{128,-1,-1},{125,-1,-1},{819,1629,1630},{128,-1,-1},{129,-1,-1},{718,-1,-1,-1,-1,-1},{128,-1,-1,-1},{128,-1,-1,-1},{124,-1,-1,-1},{348,-1,-1,-1,-1},{2048,1637,1638,1639,1640,-1,1641},{126,-1,-1,-1},{712,-1,-1,-1},{712,-1,-1,-1},{126,-1,-1,-1},{126,-1,-1},{126,-1,-1},{1437,1644,-1,1645,1646,-1,1647,-1},{128,-1,-1},{128,-1,-1},{312,-1,-1},{128,-1,-1},{628,-1,-1,-1,-1,-1},{127,-1,-1},{624,1651,1655,1662,1668,1669,1673,1681,1687,1688,1692,1693,-1},{1758,1652,1653,-1,1654,-1,-1,-1},{512,-1,-1},{517,-1,-1,-1},{172,-1,-1,-1},{7580,1656,1657,1658,1659,1660,-1,1661,-1},{491,-1,-1,-1},{427,-1,-1,-1,-1},{1052,-1,-1,-1},{751,-1,-1,-1,-1},{214,-1,-1,-1,-1},{182,-1,-1,-1},{1407,1663,1664,-1,1665,1666,-1,1667,-1},{153,-1,-1,-1},{128,-1,-1},{124,-1,-1},{218,-1,-1,-1},{168,-1,-1,-1},{162,-1,-1},{1527,-1,-1,1670,-1,1671,-1,1672,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{7508,1674,1675,1676,1677,1678,1679,1680,-1},{419,-1,-1,-1,-1},{417,-1,-1,-1,-1},{129,-1,-1},{127,-1,-1,-1},{241,-1,-1,-1,-1},{124,-1,-1},{128,-1,-1},{478,1682,1683,1684,1685,-1,1686},{126,-1,-1},{129,-1,-1,-1},{127,-1,-1,-1},{126,-1,-1},{128,-1,-1,-1},{126,-1,-1},{167,1689,1690,1691},{312,-1,-1},{128,-1,-1},{124,-1,-1},{7028,-1,-1,-1,-1,-1},{124,-1,-1},{453,1695,1696,-1,1697,-1,-1,1698,-1},{124,-1,-1},{124,-1,-1},{124,-1,-1},{152,-1,-1},{216,1700,1707,1715,1719,1725,1733,1737,1743,1744},{1738,1701,1702,1703,-1,1704,1705,1706,-1,-1},{314,-1,-1,-1},{327,-1,-1,-1,-1},{127,-1,-1,-1},{124,-1,-1},{137,-1,-1,-1,-1},{127,-1,-1},{172,1708,1709,1710,1711,1712,1713,1714},{314,-1,-1,-1},{138,-1,-1,-1,-1},{238,-1,-1,-1,-1},{128,-1,-1},{182,-1,-1},{178,-1,-1,-1,-1},{128,-1,-1},{2067,1716,-1,1717,-1,1718,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{378,-1,1720,1721,-1,1722,1723,1724,-1},{127,-1,-1},{127,-1,-1,-1},{128,-1,-1,-1},{127,-1,-1},{127,-1,-1},{1736,1726,1727,1728,-1,1729,1730,1731,-1,1732,-1},{182,-1,-1},{128,-1,-1},{128,-1,-1,-1},{128,-1,-1},{128,-1,-1},{138,-1,-1,-1},{128,-1,-1},{267,1734,-1,1735,-1,1736,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{367,1738,1739,1740,-1,1741,1742,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{178,-1,-1,-1},{178,-1,-1,-1},{256,1746,1751,1759,1768,-1,1769,1778,1787,-1,1788,1794,-1,1795,-1},{3174,1747,-1,1748,-1,1749,-1,1750,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{2107,1752,-1,1753,1754,1755,1756,1757,1758},{238,-1,-1,-1},{438,-1,-1,-1,-1},{182,-1,-1,-1,-1},{178,-1,-1,-1,-1,-1},{138,-1,-1,-1,-1,-1},{138,-1,-1,-1},{128,-1,-1},{167,1760,1761,1762,1763,-1,1764,-1,1765,1766,1767},{315,-1,-1,-1},{128,-1,-1},{124,-1,-1},{128,-1,-1},{1208,-1,-1,-1,-1},{124,-1,-1},{128,-1,-1},{127,-1,-1},{7028,-1,-1,-1,-1,-1},{718,1770,-1,1771,1772,1773,-1,1774,1775,1776,1777,-1},{124,-1,-1},{139,-1,-1,-1},{237,-1,-1,-1,-1,-1},{182,-1,-1,-1},{124,-1,-1},{127,-1,-1,-1},{127,-1,-1},{127,-1,-1},{467,1779,1780,1781,-1,1782,1783,1784,1785,1786},{182,-1,-1,-1,-1},{124,-1,-1,-1},{128,-1,-1},{128,-1,-1,-1},{218,-1,-1,-1,-1},{124,-1,-1},{182,-1,-1,-1,-1,-1},{157,-1,-1,-1,-1},{578,-1,-1,-1,-1,-1},{1576,1789,1790,-1,1791,1792,1793},{128,-1,-1},{128,-1,-1},{124,-1,-1},{128,-1,-1},{124,-1,-1},{782,-1,-1,-1,-1,-1,-1},{278,-1,-1,-1,-1},{467,1797,1802,1807,1808,1809,1814,1815,1819,1820},{852,1798,1799,1800,-1,1801,-1,-1},{124,-1,-1},{129,-1,-1},{128,-1,-1},{124,-1,-1},{1480,1803,1804,1805,1806,-1,-1},{124,-1,-1,-1},{124,-1,-1},{124,-1,-1},{156,-1,-1,-1},{164,-1,-1,-1,-1},{518,-1,-1,-1,-1,-1,-1,-1},{253,1810,1811,1812,-1,1813,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{126,-1,-1},{174,-1,-1,-1,-1},{189,-1,1816,1817,1818},{126,-1,-1},{128,-1,-1},{128,-1,-1},{126,-1,-1},{126,-1,-1},{124,1822,1823},{213,-1,-1},{213,-1,-1},{214,1825,1830,1834,1839,1843,1845,1848,1850},{637,1826,1827,1828,1829},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{647,1831,1832,1833,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{672,1835,1836,1837,1838},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{367,1840,1841,1842,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{167,1844,-1,-1},{128,-1,-1},{167,1846,1847},{128,-1,-1},{126,-1,-1},{167,1849,-1,-1},{128,-1,-1},{167,1851,-1,-1},{128,-1,-1},{265,1853,1854,1855,1856,1857,1858,-1},{7018,-1,-1,-1},{125,-1,-1},{718,-1,-1,-1,-1},{7058,-1,-1,-1,-1},{124,-1,-1},{718,-1,-1,-1,-1},{125,1860,1861},{213,-1,-1},{213,-1,-1},{214,-1,-1,-1,-1},{145,1864,1883,1904,1909,1918,1944,1951,1952},{1263,1865,1869,1873,1874,1878,1879,1880,1881,-1,1882,-1},{1370,1866,-1,1867,-1,1868,-1},{128,-1,-1},{128,-1,-1},{128,-1,-1},{367,1870,-1,1871,1872,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{312,-1,-1},{781,1875,1876,1877},{192,-1,-1},{127,-1,-1},{127,-1,-1},{1728,-1,-1,-1,-1,-1,-1,-1},{124,-1,-1},{7018,-1,-1,-1},{7068,-1,-1,-1,-1,-1},{178,-1,-1,-1},{1425,1884,1887,1888,1889,1893,1898,1899,1903},{167,1885,1886},{128,-1,-1},{126,-1,-1},{1204,-1,-1,-1,-1},{214,-1,-1,-1},{1067,1890,1891,1892,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{6047,1894,1895,1896,1897,-1},{312,-1,-1},{124,-1,-1},{128,-1,-1},{124,-1,-1},{324,-1,-1,-1,-1,-1},{1067,-1,1900,1901,1902,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{124,-1,-1},{412,1905,1906,1907,-1,1908,-1},{152,-1,-1},{231,-1,-1},{124,-1,-1},{213,-1,-1},{637,1910,1911,1912,1913,1914,1915,1916,1917},{128,-1,-1},{126,-1,-1},{182,-1,-1,-1,-1},{386,-1,-1,-1,-1,-1},{126,-1,-1},{218,-1,-1,-1,-1,-1},{126,-1,-1},{126,-1,-1},{267,1919,1924,1929,1930,1931,1937,1938,1942,1943},{834,1920,1921,1922,-1,1923,-1,-1},{125,-1,-1},{129,-1,-1},{128,-1,-1},{124,-1,-1},{1280,1925,1926,1927,1928,-1,-1},{125,-1,-1,-1},{129,-1,-1},{128,-1,-1},{136,-1,-1,-1},{162,-1,-1,-1,-1},{318,-1,-1,-1,-1,-1,-1,-1},{318,1932,1933,1934,1935,1936,-1},{126,-1,-1},{124,-1,-1},{126,-1,-1},{124,-1,-1},{124,-1,-1},{172,-1,-1,-1,-1},{189,-1,1939,1940,1941},{126,-1,-1},{128,-1,-1},{128,-1,-1},{126,-1,-1},{126,-1,-1},{251,1945,1946,1947,-1,1948,1949,-1,1950,-1,-1},{124,-1,-1,-1},{124,-1,-1,-1},{125,-1,-1},{124,-1,-1},{132,-1,-1},{124,-1,-1},{214,-1,-1,-1,-1},{215,-1,-1,-1,-1,-1,-1,-1,-1},{132,1954,1957},{124,1955,1956},{231,-1,-1},{231,-1,-1},{134,1958,1959},{213,-1,-1},{213,-1,-1},{245,1961,1965,1981,1993,1994,2007,2018,-1,2022,2028,-1,-1},{6071,1962,1963,-1,1964,-1},{182,-1,-1},{168,-1,-1,-1,-1},{178,-1,-1,-1,-1},{1653,1966,1970,1973,1977,1978,-1,1979,1980,-1},{127,1967,1968,1969},{128,-1,-1},{128,-1,-1},{128,-1,-1},{176,1971,-1,1972,-1},{128,-1,-1},{128,-1,-1},{712,1974,1975,1976},{812,-1,-1},{128,-1,-1},{128,-1,-1},{1784,-1,-1,-1,-1,-1,-1},{578,-1,-1,-1,-1},{7018,-1,-1,-1},{7018,-1,-1,-1},{563,1982,1985,-1,1986,1989,-1,1992,-1},{174,1983,-1,1984,-1},{128,-1,-1},{128,-1,-1},{4678,-1,-1,-1,-1,-1},{417,1987,-1,1988,-1},{128,-1,-1},{128,-1,-1},{157,1990,1991,-1,-1},{412,-1,-1},{128,-1,-1},{7018,-1,-1,-1},{412,-1,-1,-1},{1463,1995,1999,2000,2004,2005,-1,2006},{127,1996,1997,1998},{128,-1,-1},{128,-1,-1},{128,-1,-1},{178,-1,-1,-1},{172,2001,2002,2003},{182,-1,-1},{128,-1,-1},{128,-1,-1},{1678,-1,-1,-1,-1,-1,-1},{7018,-1,-1,-1},{718,-1,-1,-1},{1653,2008,2012,2013,-1,2014,2015,2016,2017,-1},{127,2009,2010,2011},{128,-1,-1},{128,-1,-1},{128,-1,-1},{1784,-1,-1,-1,-1,-1,-1},{7028,-1,-1,-1,-1},{2678,-1,-1,-1,-1,-1,-1},{1578,-1,-1,-1,-1,-1,-1,-1},{124,-1,-1,-1},{718,-1,-1,-1},{264,-1,2019,2020,-1,-1,2021,-1},{278,-1,-1,-1,-1},{478,-1,-1,-1,-1},{718,-1,-1,-1},{6175,2023,2024,2025,2026,2027,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{267,-1,2029,2030},{128,-1,-1},{126,-1,-1},{245,2032,2038,2042,2043,2047,2054,2055,2058,-1},{1063,2033,-1,2034,2035,-1,2036,2037},{178,-1,-1,-1},{178,-1,-1,-1},{7018,-1,-1,-1},{718,-1,-1,-1},{132,-1,-1},{1463,2039,-1,-1,2040,2041,-1,-1,-1},{7018,-1,-1,-1},{7018,-1,-1,-1},{134,-1,-1,-1},{124,-1,-1,-1,-1},{167,2044,2045,2046,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{6721,2048,2049,2050,2051,2052,2053,-1,-1},{124,-1,-1,-1},{128,-1,-1,-1},{126,-1,-1},{128,-1,-1},{156,-1,-1,-1},{128,-1,-1},{134,-1,-1,-1,-1},{167,2056,-1,2057},{128,-1,-1},{124,-1,-1},{124,-1,-1,-1},{124,2060,2062},{132,-1,2061},{213,-1,-1},{234,-1,-1,-1},{145,2064,2069,2070,2074,2075},{267,2065,2066,2067,2068},{128,-1,-1},{126,-1,-1},{128,-1,-1},{126,-1,-1},{214,-1,-1,-1,-1},{627,2071,2072,2073,-1,-1},{128,-1,-1},{126,-1,-1},{128,-1,-1},{124,-1,-1},{124,-1,-1}

};

int A, B, secret;
vector<int> cand, imp, nu;

int p[] = {1000, 100, 10, 1};
int g (int i, int j) {
	return (i/p[j]) % 10;
}

int QQ;

inline pair<int,int> fake (int x, int y);
pair<int,int> q (int i) {

	

	printf("%d%d%d%d\n", (i/1000)%10, (i/100)%10, (i/10)%10, i%10);
	fflush(stdout);
	scanf("%d %d", &A, &B);
	if (A == 4) exit(0);
	return MP(A,B);
}

inline pair<int,int> fake (int x, int y) {
	A = B = 0;
	fo(i, 0, 4) {
		if (g(x,i) == g(y,i)) A++;
		else fo(j, 0, 4) if (g(x,j) == g(y,i)) B++;
	}
	return MP(A,B);
}

vector<int> c;
void decide (int X) {
	if ((int) c.size() == 1) q(c[0]), assert(0);

	int pp = 0;
	int tt = ch[X][pp++];

	vector<int> v[5][5];
	fo(i, 0, 5) fo(j, 0, 5) v[i][j].clear();
	for (int i : c) fake(tt, i), v[A][B].PB(i);

	pair<int,int> rr = q(tt);
	nu.clear();
	for (int i : c) if (fake(tt, i) == rr) nu.PB(i);
	swap(c, nu);

	int child = -1;
	fo(i, 0, 5) fo(j, 0, 5) if (v[i][j].size()) {
		if (i == rr.first && j == rr.second) {
			child = ch[X][pp++];
		} else pp++;
	}

	decide(child-1);
}

int main () {
	


	fo(i, 0, 10000) {
		set<int> s;
		fo(j, 0, 4) s.insert(g(i,j));
		if ((int) s.size() == 4) c.PB(i);
	}

	decide(0);

	return 0;
}
