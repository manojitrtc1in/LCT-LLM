

using namespace std;

pair<int, pair<char, string>> wyniki[] = {
  {0, {'F', "(!x&x)"}},
  {0, {'T', "!x&x"}},
  {0, {'E', "!x&x"}},
  {1, {'F', "!(x|y|z)"}},
  {1, {'T', "!(x|y|z)"}},
  {1, {'E', "!(x|y|z)"}},
  {2, {'F', "!(!z|x|y)"}},
  {2, {'T', "!x&!y&z"}},
  {2, {'E', "!x&!y&z"}},
  {3, {'F', "!(x|y)"}},
  {3, {'T', "!x&!y"}},
  {3, {'E', "!x&!y"}},
  {4, {'F', "!(!y|x|z)"}},
  {4, {'T', "!x&!z&y"}},
  {4, {'E', "!x&!z&y"}},
  {5, {'F', "!(x|z)"}},
  {5, {'T', "!x&!z"}},
  {5, {'E', "!x&!z"}},
  {6, {'F', "!(!y&!z|x|y&z)"}},
  {6, {'T', "!(!y&!z|x|y&z)"}},
  {6, {'E', "!(!y&!z|x|y&z)"}},
  {7, {'F', "!(x|y&z)"}},
  {7, {'T', "!(x|y&z)"}},
  {7, {'E', "!(x|y&z)"}},
  {8, {'F', "(!x&y&z)"}},
  {8, {'T', "!x&y&z"}},
  {8, {'E', "!x&y&z"}},
  {9, {'F', "!(!y&z|!z&y|x)"}},
  {9, {'T', "!(!y&z|!z&y|x)"}},
  {9, {'E', "!(!y&z|!z&y|x)"}},
  {10, {'F', "(!x&z)"}},
  {10, {'T', "!x&z"}},
  {10, {'E', "!x&z"}},
  {11, {'F', "!(!z&y|x)"}},
  {11, {'T', "!(!z&y|x)"}},
  {11, {'E', "!(!z&y|x)"}},
  {12, {'F', "(!x&y)"}},
  {12, {'T', "!x&y"}},
  {12, {'E', "!x&y"}},
  {13, {'F', "!(!y&z|x)"}},
  {13, {'T', "!(!y&z|x)"}},
  {13, {'E', "!(!y&z|x)"}},
  {14, {'F', "!(!y&!z|x)"}},
  {14, {'T', "!x&(y|z)"}},
  {14, {'E', "!x&(y|z)"}},
  {15, {'F', "!x"}},
  {15, {'T', "!x"}},
  {15, {'E', "!x"}},
  {16, {'F', "!(!x|y|z)"}},
  {16, {'T', "!y&!z&x"}},
  {16, {'E', "!y&!z&x"}},
  {17, {'F', "!(y|z)"}},
  {17, {'T', "!y&!z"}},
  {17, {'E', "!y&!z"}},
  {18, {'F', "!(!x&!z|x&z|y)"}},
  {18, {'T', "!(!x&!z|x&z|y)"}},
  {18, {'E', "!(!x&!z|x&z|y)"}},
  {19, {'F', "!(x&z|y)"}},
  {19, {'T', "!(x&z|y)"}},
  {19, {'E', "!(x&z|y)"}},
  {20, {'F', "!(!x&!y|x&y|z)"}},
  {20, {'T', "!(!x&!y|x&y|z)"}},
  {20, {'E', "!(!x&!y|x&y|z)"}},
  {21, {'F', "!(x&y|z)"}},
  {21, {'T', "!(x&y|z)"}},
  {21, {'E', "!(x&y|z)"}},
  {22, {'F', "!(!(x|y|z)|(x|y)&z|x&y)"}},
  {22, {'T', "!((x|y)&z|x&y)&(x|y|z)"}},
  {22, {'E', "!(!x&!y|x&y|z)|!x&!y&z"}},
  {23, {'F', "!((x|y)&z|x&y)"}},
  {23, {'T', "!((x|y)&z|x&y)"}},
  {23, {'E', "!((x|y)&z|x&y)"}},
  {24, {'F', "(!x&y&z|!y&!z&x)"}},
  {24, {'T', "(!x&y&z|!y&!z&x)"}},
  {24, {'E', "!x&y&z|!y&!z&x"}},
  {25, {'F', "(!x&y&z|!y&!z)"}},
  {25, {'T', "(!x&y&z|!y&!z)"}},
  {25, {'E', "!x&y&z|!y&!z"}},
  {26, {'F', "(!x&z|!y&!z&x)"}},
  {26, {'T', "(!x&z|!y&!z&x)"}},
  {26, {'E', "!x&z|!y&!z&x"}},
  {27, {'F', "!(!z&y|x&z)"}},
  {27, {'T', "!(!z&y|x&z)"}},
  {27, {'E', "!x&z|!y&!z"}},
  {28, {'F', "(!x&y|!y&!z&x)"}},
  {28, {'T', "(!x&y|!y&!z&x)"}},
  {28, {'E', "!x&y|!y&!z&x"}},
  {29, {'F', "!(!y&z|x&y)"}},
  {29, {'T', "!(!y&z|x&y)"}},
  {29, {'E', "!x&y|!y&!z"}},
  {30, {'F', "(!x&(y|z)|!y&!z&x)"}},
  {30, {'T', "!((y|z)&x)&(x|y|z)"}},
  {30, {'E', "!x&(y|z)|!y&!z&x"}},
  {31, {'F', "!((y|z)&x)"}},
  {31, {'T', "!((y|z)&x)"}},
  {31, {'E', "!x|!y&!z"}},
  {32, {'F', "(!y&x&z)"}},
  {32, {'T', "!y&x&z"}},
  {32, {'E', "!y&x&z"}},
  {33, {'F', "!(!x&z|!z&x|y)"}},
  {33, {'T', "!(!x&z|!z&x|y)"}},
  {33, {'E', "!(!x&z|!z&x|y)"}},
  {34, {'F', "(!y&z)"}},
  {34, {'T', "!y&z"}},
  {34, {'E', "!y&z"}},
  {35, {'F', "!(!z&x|y)"}},
  {35, {'T', "!(!z&x|y)"}},
  {35, {'E', "!(!z&x|y)"}},
  {36, {'F', "(!x&!z&y|!y&x&z)"}},
  {36, {'T', "(!x&!z&y|!y&x&z)"}},
  {36, {'E', "!x&!z&y|!y&x&z"}},
  {37, {'F', "(!x&!z|!y&x&z)"}},
  {37, {'T', "(!x&!z|!y&x&z)"}},
  {37, {'E', "!x&!z|!y&x&z"}},
  {38, {'F', "(!x&!z&y|!y&z)"}},
  {38, {'T', "(!x&!z&y|!y&z)"}},
  {38, {'E', "!x&!z&y|!y&z"}},
  {39, {'F', "!(!z&x|y&z)"}},
  {39, {'T', "!(!z&x|y&z)"}},
  {39, {'E', "!x&!z|!y&z"}},
  {40, {'F', "!(!x&!y|!z|x&y)"}},
  {40, {'T', "(!x&y|!y&x)&z"}},
  {40, {'E', "!x&y&z|!y&x&z"}},
  {41, {'F', "!(!x&!y&z|!z&(x|y)|x&y)"}},
  {41, {'T', "!(!x&!y&z|!z&(x|y)|x&y)"}},
  {41, {'E', "!(!x&z|!z&x|y)|!x&y&z"}},
  {42, {'F', "!(!z|x&y)"}},
  {42, {'T', "!(x&y)&z"}},
  {42, {'E', "!(x&y)&z"}},
  {43, {'F', "!(!z&(x|y)|x&y)"}},
  {43, {'T', "!(!z&(x|y)|x&y)"}},
  {43, {'E', "!(!z&x|y)|!x&z"}},
  {44, {'F', "(!x&y|!y&x&z)"}},
  {44, {'T', "(!x&y|!y&x&z)"}},
  {44, {'E', "!x&y|!y&x&z"}},
  {45, {'F', "(!(!y&z|x)|!y&x&z)"}},
  {45, {'T', "(!(!y&z|x)|!y&x&z)"}},
  {45, {'E', "!(!y&z|x)|!y&x&z"}},
  {46, {'F', "(!x&y|!y&z)"}},
  {46, {'T', "(!x&y|!y&z)"}},
  {46, {'E', "!x&y|!y&z"}},
  {47, {'F', "(!x|!y&z)"}},
  {47, {'T', "(!x|!y&z)"}},
  {47, {'E', "!x|!y&z"}},
  {48, {'F', "(!y&x)"}},
  {48, {'T', "!y&x"}},
  {48, {'E', "!y&x"}},
  {49, {'F', "!(!x&z|y)"}},
  {49, {'T', "!(!x&z|y)"}},
  {49, {'E', "!(!x&z|y)"}},
  {50, {'F', "!(!x&!z|y)"}},
  {50, {'T', "!y&(x|z)"}},
  {50, {'E', "!y&(x|z)"}},
  {51, {'F', "!y"}},
  {51, {'T', "!y"}},
  {51, {'E', "!y"}},
  {52, {'F', "(!x&!z&y|!y&x)"}},
  {52, {'T', "(!x&!z&y|!y&x)"}},
  {52, {'E', "!x&!z&y|!y&x"}},
  {53, {'F', "!(!x&z|x&y)"}},
  {53, {'T', "!(!x&z|x&y)"}},
  {53, {'E', "!x&!z|!y&x"}},
  {54, {'F', "(!x&!z&y|!y&(x|z))"}},
  {54, {'T', "!((x|z)&y)&(x|y|z)"}},
  {54, {'E', "!x&!z&y|!y&(x|z)"}},
  {55, {'F', "!((x|z)&y)"}},
  {55, {'T', "!((x|z)&y)"}},
  {55, {'E', "!x&!z|!y"}},
  {56, {'F', "(!x&y&z|!y&x)"}},
  {56, {'T', "(!x&y&z|!y&x)"}},
  {56, {'E', "!x&y&z|!y&x"}},
  {57, {'F', "(!(!x&z|y)|!x&y&z)"}},
  {57, {'T', "(!(!x&z|y)|!x&y&z)"}},
  {57, {'E', "!(!x&z|y)|!x&y&z"}},
  {58, {'F', "(!x&z|!y&x)"}},
  {58, {'T', "(!x&z|!y&x)"}},
  {58, {'E', "!x&z|!y&x"}},
  {59, {'F', "(!x&z|!y)"}},
  {59, {'T', "(!x&z|!y)"}},
  {59, {'E', "!x&z|!y"}},
  {60, {'F', "(!x&y|!y&x)"}},
  {60, {'T', "(!x&y|!y&x)"}},
  {60, {'E', "!x&y|!y&x"}},
  {61, {'F', "!(!x&!y&z|x&y)"}},
  {61, {'T', "!(!x&!y&z|x&y)"}},
  {61, {'E', "!(!x&!y&z|x&y)"}},
  {62, {'F', "!(!(x|y|z)|x&y)"}},
  {62, {'T', "!(x&y)&(x|y|z)"}},
  {62, {'E', "!x&(y|z)|!y&x"}},
  {63, {'F', "!(x&y)"}},
  {63, {'T', "!(x&y)"}},
  {63, {'E', "!x|!y"}},
  {64, {'F', "(!z&x&y)"}},
  {64, {'T', "!z&x&y"}},
  {64, {'E', "!z&x&y"}},
  {65, {'F', "!(!x&y|!y&x|z)"}},
  {65, {'T', "!(!x&y|!y&x|z)"}},
  {65, {'E', "!(!x&y|!y&x|z)"}},
  {66, {'F', "(!x&!y&z|!z&x&y)"}},
  {66, {'T', "(!x&!y&z|!z&x&y)"}},
  {66, {'E', "!x&!y&z|!z&x&y"}},
  {67, {'F', "(!x&!y|!z&x&y)"}},
  {67, {'T', "(!x&!y|!z&x&y)"}},
  {67, {'E', "!x&!y|!z&x&y"}},
  {68, {'F', "(!z&y)"}},
  {68, {'T', "!z&y"}},
  {68, {'E', "!z&y"}},
  {69, {'F', "!(!y&x|z)"}},
  {69, {'T', "!(!y&x|z)"}},
  {69, {'E', "!(!y&x|z)"}},
  {70, {'F', "(!x&!y&z|!z&y)"}},
  {70, {'T', "(!x&!y&z|!z&y)"}},
  {70, {'E', "!x&!y&z|!z&y"}},
  {71, {'F', "!(!y&x|y&z)"}},
  {71, {'T', "!(!y&x|y&z)"}},
  {71, {'E', "!x&!y|!z&y"}},
  {72, {'F', "!(!x&!z|!y|x&z)"}},
  {72, {'T', "(!x&z|!z&x)&y"}},
  {72, {'E', "!x&y&z|!z&x&y"}},
  {73, {'F', "!(!x&!z&y|!y&(x|z)|x&z)"}},
  {73, {'T', "!(!x&!z&y|!y&(x|z)|x&z)"}},
  {73, {'E', "!(!x&y|!y&x|z)|!x&y&z"}},
  {74, {'F', "(!x&z|!z&x&y)"}},
  {74, {'T', "(!x&z|!z&x&y)"}},
  {74, {'E', "!x&z|!z&x&y"}},
  {75, {'F', "(!(!z&y|x)|!z&x&y)"}},
  {75, {'T', "(!(!z&y|x)|!z&x&y)"}},
  {75, {'E', "!(!z&y|x)|!z&x&y"}},
  {76, {'F', "!(!y|x&z)"}},
  {76, {'T', "!(x&z)&y"}},
  {76, {'E', "!(x&z)&y"}},
  {77, {'F', "!(!y&(x|z)|x&z)"}},
  {77, {'T', "!(!y&(x|z)|x&z)"}},
  {77, {'E', "!(!y&x|z)|!x&y"}},
  {78, {'F', "(!x&z|!z&y)"}},
  {78, {'T', "(!x&z|!z&y)"}},
  {78, {'E', "!x&z|!z&y"}},
  {79, {'F', "(!x|!z&y)"}},
  {79, {'T', "(!x|!z&y)"}},
  {79, {'E', "!x|!z&y"}},
  {80, {'F', "(!z&x)"}},
  {80, {'T', "!z&x"}},
  {80, {'E', "!z&x"}},
  {81, {'F', "!(!x&y|z)"}},
  {81, {'T', "!(!x&y|z)"}},
  {81, {'E', "!(!x&y|z)"}},
  {82, {'F', "(!x&!y&z|!z&x)"}},
  {82, {'T', "(!x&!y&z|!z&x)"}},
  {82, {'E', "!x&!y&z|!z&x"}},
  {83, {'F', "!(!x&y|x&z)"}},
  {83, {'T', "!(!x&y|x&z)"}},
  {83, {'E', "!x&!y|!z&x"}},
  {84, {'F', "!(!x&!y|z)"}},
  {84, {'T', "!z&(x|y)"}},
  {84, {'E', "!z&(x|y)"}},
  {85, {'F', "!z"}},
  {85, {'T', "!z"}},
  {85, {'E', "!z"}},
  {86, {'F', "(!x&!y&z|!z&(x|y))"}},
  {86, {'T', "!((x|y)&z)&(x|y|z)"}},
  {86, {'E', "!x&!y&z|!z&(x|y)"}},
  {87, {'F', "!((x|y)&z)"}},
  {87, {'T', "!((x|y)&z)"}},
  {87, {'E', "!x&!y|!z"}},
  {88, {'F', "(!x&y&z|!z&x)"}},
  {88, {'T', "(!x&y&z|!z&x)"}},
  {88, {'E', "!x&y&z|!z&x"}},
  {89, {'F', "(!(!x&y|z)|!x&y&z)"}},
  {89, {'T', "(!(!x&y|z)|!x&y&z)"}},
  {89, {'E', "!(!x&y|z)|!x&y&z"}},
  {90, {'F', "(!x&z|!z&x)"}},
  {90, {'T', "(!x&z|!z&x)"}},
  {90, {'E', "!x&z|!z&x"}},
  {91, {'F', "!(!x&!z&y|x&z)"}},
  {91, {'T', "!(!x&!z&y|x&z)"}},
  {91, {'E', "!(!x&!z&y|x&z)"}},
  {92, {'F', "(!x&y|!z&x)"}},
  {92, {'T', "(!x&y|!z&x)"}},
  {92, {'E', "!x&y|!z&x"}},
  {93, {'F', "(!x&y|!z)"}},
  {93, {'T', "(!x&y|!z)"}},
  {93, {'E', "!x&y|!z"}},
  {94, {'F', "!(!(x|y|z)|x&z)"}},
  {94, {'T', "!(x&z)&(x|y|z)"}},
  {94, {'E', "!x&(y|z)|!z&x"}},
  {95, {'F', "!(x&z)"}},
  {95, {'T', "!(x&z)"}},
  {95, {'E', "!x|!z"}},
  {96, {'F', "!(!x|!y&!z|y&z)"}},
  {96, {'T', "(!y&z|!z&y)&x"}},
  {96, {'E', "!y&x&z|!z&x&y"}},
  {97, {'F', "!(!x&(y|z)|!y&!z&x|y&z)"}},
  {97, {'T', "!(!x&(y|z)|!y&!z&x|y&z)"}},
  {97, {'E', "!(!x&y|!y&x|z)|!y&x&z"}},
  {98, {'F', "(!y&z|!z&x&y)"}},
  {98, {'T', "(!y&z|!z&x&y)"}},
  {98, {'E', "!y&z|!z&x&y"}},
  {99, {'F', "(!(!z&x|y)|!z&x&y)"}},
  {99, {'T', "(!(!z&x|y)|!z&x&y)"}},
  {99, {'E', "!(!z&x|y)|!z&x&y"}},
  {100, {'F', "(!y&x&z|!z&y)"}},
  {100, {'T', "(!y&x&z|!z&y)"}},
  {100, {'E', "!y&x&z|!z&y"}},
  {101, {'F', "(!(!y&x|z)|!y&x&z)"}},
  {101, {'T', "(!(!y&x|z)|!y&x&z)"}},
  {101, {'E', "!(!y&x|z)|!y&x&z"}},
  {102, {'F', "(!y&z|!z&y)"}},
  {102, {'T', "(!y&z|!z&y)"}},
  {102, {'E', "!y&z|!z&y"}},
  {103, {'F', "!(!y&!z&x|y&z)"}},
  {103, {'T', "!(!y&!z&x|y&z)"}},
  {103, {'E', "!(!y&!z&x|y&z)"}},
  {104, {'F', "(!x&y&z|!y&x&z|!z&x&y)"}},
  {104, {'T', "!(!x&!y|x&y&z)&(x&y|z)"}},
  {104, {'E', "!x&y&z|!y&x&z|!z&x&y"}},
  {105, {'F', "(!(!x&y|!y&x|z)|!x&y&z|!y&x&z)"}},
  {105, {'T', "(!x&!y|x&y|z)&(!x&y|!y&x|!z)"}},
  {105, {'E', "!(!x&y|!y&x|z)|!x&y&z|!y&x&z"}},
  {106, {'F', "!(!(x&y|z)|x&y&z)"}},
  {106, {'T', "!(x&y&z)&(x&y|z)"}},
  {106, {'E', "!(x&y)&z|!z&x&y"}},
  {107, {'F', "!(!(!x&!y|x&y|z)|x&y&z)"}},
  {107, {'T', "!(x&y&z)&(!x&!y|x&y|z)"}},
  {107, {'E', "!(!z&x|y)|!x&z|!z&x&y"}},
  {108, {'F', "!(!(x&z|y)|x&y&z)"}},
  {108, {'T', "!(x&y&z)&(x&z|y)"}},
  {108, {'E', "!(x&z)&y|!y&x&z"}},
  {109, {'F', "!(!(!x&!z|x&z|y)|x&y&z)"}},
  {109, {'T', "!(x&y&z)&(!x&!z|x&z|y)"}},
  {109, {'E', "!(!y&x|z)|!x&y|!y&x&z"}},
  {110, {'F', "!(!y&!z|x&y&z)"}},
  {110, {'T', "!(!y&!z|x&y&z)"}},
  {110, {'E', "!(x&y)&z|!z&y"}},
  {111, {'F', "(!x|!y&z|!z&y)"}},
  {111, {'T', "(!x|!y&z|!z&y)"}},
  {111, {'E', "!x|!y&z|!z&y"}},
  {112, {'F', "!(!x|y&z)"}},
  {112, {'T', "!(y&z)&x"}},
  {112, {'E', "!(y&z)&x"}},
  {113, {'F', "!(!x&(y|z)|y&z)"}},
  {113, {'T', "!(!x&(y|z)|y&z)"}},
  {113, {'E', "!(!x&y|z)|!y&x"}},
  {114, {'F', "(!y&z|!z&x)"}},
  {114, {'T', "(!y&z|!z&x)"}},
  {114, {'E', "!y&z|!z&x"}},
  {115, {'F', "(!y|!z&x)"}},
  {115, {'T', "(!y|!z&x)"}},
  {115, {'E', "!y|!z&x"}},
  {116, {'F', "(!y&x|!z&y)"}},
  {116, {'T', "(!y&x|!z&y)"}},
  {116, {'E', "!y&x|!z&y"}},
  {117, {'F', "(!y&x|!z)"}},
  {117, {'T', "(!y&x|!z)"}},
  {117, {'E', "!y&x|!z"}},
  {118, {'F', "!(!(x|y|z)|y&z)"}},
  {118, {'T', "!(y&z)&(x|y|z)"}},
  {118, {'E', "!y&(x|z)|!z&y"}},
  {119, {'F', "!(y&z)"}},
  {119, {'T', "!(y&z)"}},
  {119, {'E', "!y|!z"}},
  {120, {'F', "!(!(x|y&z)|x&y&z)"}},
  {120, {'T', "!(x&y&z)&(x|y&z)"}},
  {120, {'E', "!(y&z)&x|!x&y&z"}},
  {121, {'F', "!(!(!y&!z|x|y&z)|x&y&z)"}},
  {121, {'T', "!(x&y&z)&(!y&!z|x|y&z)"}},
  {121, {'E', "!(!x&y|z)|!x&y&z|!y&x"}},
  {122, {'F', "!(!x&!z|x&y&z)"}},
  {122, {'T', "!(!x&!z|x&y&z)"}},
  {122, {'E', "!(x&y)&z|!z&x"}},
  {123, {'F', "(!x&z|!y|!z&x)"}},
  {123, {'T', "(!x&z|!y|!z&x)"}},
  {123, {'E', "!x&z|!y|!z&x"}},
  {124, {'F', "!(!x&!y|x&y&z)"}},
  {124, {'T', "!(!x&!y|x&y&z)"}},
  {124, {'E', "!(x&z)&y|!y&x"}},
  {125, {'F', "(!x&y|!y&x|!z)"}},
  {125, {'T', "(!x&y|!y&x|!z)"}},
  {125, {'E', "!x&y|!y&x|!z"}},
  {126, {'F', "(!x&y|!y&z|!z&x)"}},
  {126, {'T', "!(x&y&z)&(x|y|z)"}},
  {126, {'E', "!x&y|!y&z|!z&x"}},
  {127, {'F', "!(x&y&z)"}},
  {127, {'T', "!(x&y&z)"}},
  {127, {'E', "!(x&y&z)"}},
  {128, {'F', "(x&y&z)"}},
  {128, {'T', "x&y&z"}},
  {128, {'E', "x&y&z"}},
  {129, {'F', "(!(x|y|z)|x&y&z)"}},
  {129, {'T', "(!(x|y|z)|x&y&z)"}},
  {129, {'E', "!(x|y|z)|x&y&z"}},
  {130, {'F', "!(!x&y|!y&x|!z)"}},
  {130, {'T', "(!x&!y|x&y)&z"}},
  {130, {'E', "!x&!y&z|x&y&z"}},
  {131, {'F', "(!x&!y|x&y&z)"}},
  {131, {'T', "(!x&!y|x&y&z)"}},
  {131, {'E', "!x&!y|x&y&z"}},
  {132, {'F', "!(!x&z|!y|!z&x)"}},
  {132, {'T', "(!x&!z|x&z)&y"}},
  {132, {'E', "!x&!z&y|x&y&z"}},
  {133, {'F', "(!x&!z|x&y&z)"}},
  {133, {'T', "(!x&!z|x&y&z)"}},
  {133, {'E', "!x&!z|x&y&z"}},
  {134, {'F', "(!(!y&!z|x|y&z)|x&y&z)"}},
  {134, {'T', "(!(!y&!z|x|y&z)|x&y&z)"}},
  {134, {'E', "!(!y&!z|x|y&z)|x&y&z"}},
  {135, {'F', "(!(x|y&z)|x&y&z)"}},
  {135, {'T', "(!(x|y&z)|x&y&z)"}},
  {135, {'E', "!(x|y&z)|x&y&z"}},
  {136, {'F', "(y&z)"}},
  {136, {'T', "y&z"}},
  {136, {'E', "y&z"}},
  {137, {'F', "(!(x|y|z)|y&z)"}},
  {137, {'T', "(!(x|y|z)|y&z)"}},
  {137, {'E', "!(x|y|z)|y&z"}},
  {138, {'F', "!(!y&x|!z)"}},
  {138, {'T', "(!x|y)&z"}},
  {138, {'E', "!x&z|y&z"}},
  {139, {'F', "(!x&!y|y&z)"}},
  {139, {'T', "(!x&!y|y&z)"}},
  {139, {'E', "!x&!y|y&z"}},
  {140, {'F', "!(!y|!z&x)"}},
  {140, {'T', "(!x|z)&y"}},
  {140, {'E', "!x&y|y&z"}},
  {141, {'F', "(!x&!z|y&z)"}},
  {141, {'T', "(!x&!z|y&z)"}},
  {141, {'E', "!x&!z|y&z"}},
  {142, {'F', "(!x&(y|z)|y&z)"}},
  {142, {'T', "(!x&(y|z)|y&z)"}},
  {142, {'E', "!x&(y|z)|y&z"}},
  {143, {'F', "(!x|y&z)"}},
  {143, {'T', "(!x|y&z)"}},
  {143, {'E', "!x|y&z"}},
  {144, {'F', "!(!x|!y&z|!z&y)"}},
  {144, {'T', "(!y&!z|y&z)&x"}},
  {144, {'E', "!y&!z&x|x&y&z"}},
  {145, {'F', "(!y&!z|x&y&z)"}},
  {145, {'T', "(!y&!z|x&y&z)"}},
  {145, {'E', "!y&!z|x&y&z"}},
  {146, {'F', "(!(!x&!z|x&z|y)|x&y&z)"}},
  {146, {'T', "(!(!x&!z|x&z|y)|x&y&z)"}},
  {146, {'E', "!(!x&!z|x&z|y)|x&y&z"}},
  {147, {'F', "(!(x&z|y)|x&y&z)"}},
  {147, {'T', "(!(x&z|y)|x&y&z)"}},
  {147, {'E', "!(x&z|y)|x&y&z"}},
  {148, {'F', "(!(!x&!y|x&y|z)|x&y&z)"}},
  {148, {'T', "(!(!x&!y|x&y|z)|x&y&z)"}},
  {148, {'E', "!(!x&!y|x&y|z)|x&y&z"}},
  {149, {'F', "(!(x&y|z)|x&y&z)"}},
  {149, {'T', "(!(x&y|z)|x&y&z)"}},
  {149, {'E', "!(x&y|z)|x&y&z"}},
  {150, {'F', "(!(!x&!y|x&y|z)|!x&!y&z|x&y&z)"}},
  {150, {'T', "(!x&!y|!z|x&y)&(!x&y|!y&x|z)"}},
  {150, {'E', "!(!x&!y|x&y|z)|!x&!y&z|x&y&z"}},
  {151, {'F', "(!((x|y)&z|x&y)|x&y&z)"}},
  {151, {'T', "(!((x|y)&z|x&y)|x&y&z)"}},
  {151, {'E', "!((x|y)&z|x&y)|x&y&z"}},
  {152, {'F', "(!y&!z&x|y&z)"}},
  {152, {'T', "(!y&!z&x|y&z)"}},
  {152, {'E', "!y&!z&x|y&z"}},
  {153, {'F', "(!y&!z|y&z)"}},
  {153, {'T', "(!y&!z|y&z)"}},
  {153, {'E', "!y&!z|y&z"}},
  {154, {'F', "(!x&z|!y&!z&x|y&z)"}},
  {154, {'T', "!(!y&x&z)&(!y&x|z)"}},
  {154, {'E', "!x&z|!y&!z&x|y&z"}},
  {155, {'F', "!(!y&x&z|!z&y)"}},
  {155, {'T', "!(!y&x&z|!z&y)"}},
  {155, {'E', "!(x&z|y)|y&z"}},
  {156, {'F', "(!x&y|!y&!z&x|y&z)"}},
  {156, {'T', "!(!z&x&y)&(!z&x|y)"}},
  {156, {'E', "!x&y|!y&!z&x|y&z"}},
  {157, {'F', "!(!y&z|!z&x&y)"}},
  {157, {'T', "!(!y&z|!z&x&y)"}},
  {157, {'E', "!(x&y|z)|y&z"}},
  {158, {'F', "(!x&(y|z)|!y&!z&x|y&z)"}},
  {158, {'T', "(!x&(y|z)|!y&!z&x|y&z)"}},
  {158, {'E', "!x&(y|z)|!y&!z&x|y&z"}},
  {159, {'F', "(!x|!y&!z|y&z)"}},
  {159, {'T', "(!x|!y&!z|y&z)"}},
  {159, {'E', "!x|!y&!z|y&z"}},
  {160, {'F', "(x&z)"}},
  {160, {'T', "x&z"}},
  {160, {'E', "x&z"}},
  {161, {'F', "(!(x|y|z)|x&z)"}},
  {161, {'T', "(!(x|y|z)|x&z)"}},
  {161, {'E', "!(x|y|z)|x&z"}},
  {162, {'F', "!(!x&y|!z)"}},
  {162, {'T', "(!y|x)&z"}},
  {162, {'E', "!y&z|x&z"}},
  {163, {'F', "(!x&!y|x&z)"}},
  {163, {'T', "(!x&!y|x&z)"}},
  {163, {'E', "!x&!y|x&z"}},
  {164, {'F', "(!x&!z&y|x&z)"}},
  {164, {'T', "(!x&!z&y|x&z)"}},
  {164, {'E', "!x&!z&y|x&z"}},
  {165, {'F', "(!x&!z|x&z)"}},
  {165, {'T', "(!x&!z|x&z)"}},
  {165, {'E', "!x&!z|x&z"}},
  {166, {'F', "(!x&!z&y|!y&z|x&z)"}},
  {166, {'T', "!(!x&y&z)&(!x&y|z)"}},
  {166, {'E', "!x&!z&y|!y&z|x&z"}},
  {167, {'F', "!(!x&y&z|!z&x)"}},
  {167, {'T', "!(!x&y&z|!z&x)"}},
  {167, {'E', "!(x|y&z)|x&z"}},
  {168, {'F', "((x|y)&z)"}},
  {168, {'T', "(x|y)&z"}},
  {168, {'E', "(x|y)&z"}},
  {169, {'F', "(!(x|y|z)|(x|y)&z)"}},
  {169, {'T', "(!(x|y|z)|(x|y)&z)"}},
  {169, {'E', "!(x|y|z)|(x|y)&z"}},
  {170, {'F', "z"}},
  {170, {'T', "z"}},
  {170, {'E', "z"}},
  {171, {'F', "(!x&!y|z)"}},
  {171, {'T', "(!x&!y|z)"}},
  {171, {'E', "!x&!y|z"}},
  {172, {'F', "(!x&y|x&z)"}},
  {172, {'T', "(!x&y|x&z)"}},
  {172, {'E', "!x&y|x&z"}},
  {173, {'F', "!(!x&!y&z|!z&x)"}},
  {173, {'T', "!(!x&!y&z|!z&x)"}},
  {173, {'E', "!(!y&z|x)|x&z"}},
  {174, {'F', "(!x&y|z)"}},
  {174, {'T', "(!x&y|z)"}},
  {174, {'E', "!x&y|z"}},
  {175, {'F', "(!x|z)"}},
  {175, {'T', "(!x|z)"}},
  {175, {'E', "!x|z"}},
  {176, {'F', "!(!x|!z&y)"}},
  {176, {'T', "(!y|z)&x"}},
  {176, {'E', "!y&x|x&z"}},
  {177, {'F', "(!y&!z|x&z)"}},
  {177, {'T', "(!y&!z|x&z)"}},
  {177, {'E', "!y&!z|x&z"}},
  {178, {'F', "(!y&(x|z)|x&z)"}},
  {178, {'T', "(!y&(x|z)|x&z)"}},
  {178, {'E', "!y&(x|z)|x&z"}},
  {179, {'F', "(!y|x&z)"}},
  {179, {'T', "(!y|x&z)"}},
  {179, {'E', "!y|x&z"}},
  {180, {'F', "(!x&!z&y|!y&x|x&z)"}},
  {180, {'T', "!(!z&x&y)&(!z&y|x)"}},
  {180, {'E', "!x&!z&y|!y&x|x&z"}},
  {181, {'F', "!(!x&z|!z&x&y)"}},
  {181, {'T', "!(!x&z|!z&x&y)"}},
  {181, {'E', "!(x&y|z)|x&z"}},
  {182, {'F', "(!x&!z&y|!y&(x|z)|x&z)"}},
  {182, {'T', "(!x&!z&y|!y&(x|z)|x&z)"}},
  {182, {'E', "!x&!z&y|!y&(x|z)|x&z"}},
  {183, {'F', "(!x&!z|!y|x&z)"}},
  {183, {'T', "(!x&!z|!y|x&z)"}},
  {183, {'E', "!x&!z|!y|x&z"}},
  {184, {'F', "(!y&x|y&z)"}},
  {184, {'T', "(!y&x|y&z)"}},
  {184, {'E', "!y&x|y&z"}},
  {185, {'F', "!(!x&!y&z|!z&y)"}},
  {185, {'T', "!(!x&!y&z|!z&y)"}},
  {185, {'E', "!(!x&z|y)|y&z"}},
  {186, {'F', "(!y&x|z)"}},
  {186, {'T', "(!y&x|z)"}},
  {186, {'E', "!y&x|z"}},
  {187, {'F', "(!y|z)"}},
  {187, {'T', "(!y|z)"}},
  {187, {'E', "!y|z"}},
  {188, {'F', "!(!x&!y|!z&x&y)"}},
  {188, {'T', "!(!x&!y|!z&x&y)"}},
  {188, {'E', "!x&y|!y&x|x&z"}},
  {189, {'F', "(!x&!z|!y&x|y&z)"}},
  {189, {'T', "(!x&!z|!y&x|y&z)"}},
  {189, {'E', "!x&!z|!y&x|y&z"}},
  {190, {'F', "(!x&y|!y&x|z)"}},
  {190, {'T', "(!x&y|!y&x|z)"}},
  {190, {'E', "!x&y|!y&x|z"}},
  {191, {'F', "!(!z&x&y)"}},
  {191, {'T', "!(!z&x&y)"}},
  {191, {'E', "!x|!y|z"}},
  {192, {'F', "(x&y)"}},
  {192, {'T', "x&y"}},
  {192, {'E', "x&y"}},
  {193, {'F', "(!(x|y|z)|x&y)"}},
  {193, {'T', "(!(x|y|z)|x&y)"}},
  {193, {'E', "!(x|y|z)|x&y"}},
  {194, {'F', "(!x&!y&z|x&y)"}},
  {194, {'T', "(!x&!y&z|x&y)"}},
  {194, {'E', "!x&!y&z|x&y"}},
  {195, {'F', "(!x&!y|x&y)"}},
  {195, {'T', "(!x&!y|x&y)"}},
  {195, {'E', "!x&!y|x&y"}},
  {196, {'F', "!(!x&z|!y)"}},
  {196, {'T', "(!z|x)&y"}},
  {196, {'E', "!z&y|x&y"}},
  {197, {'F', "(!x&!z|x&y)"}},
  {197, {'T', "(!x&!z|x&y)"}},
  {197, {'E', "!x&!z|x&y"}},
  {198, {'F', "(!x&!y&z|!z&y|x&y)"}},
  {198, {'T', "!(!x&y&z)&(!x&z|y)"}},
  {198, {'E', "!x&!y&z|!z&y|x&y"}},
  {199, {'F', "!(!x&y&z|!y&x)"}},
  {199, {'T', "!(!x&y&z|!y&x)"}},
  {199, {'E', "!(x|y&z)|x&y"}},
  {200, {'F', "((x|z)&y)"}},
  {200, {'T', "(x|z)&y"}},
  {200, {'E', "(x|z)&y"}},
  {201, {'F', "(!(x|y|z)|(x|z)&y)"}},
  {201, {'T', "(!(x|y|z)|(x|z)&y)"}},
  {201, {'E', "!(x|y|z)|(x|z)&y"}},
  {202, {'F', "(!x&z|x&y)"}},
  {202, {'T', "(!x&z|x&y)"}},
  {202, {'E', "!x&z|x&y"}},
  {203, {'F', "!(!x&!z&y|!y&x)"}},
  {203, {'T', "!(!x&!z&y|!y&x)"}},
  {203, {'E', "!(!z&y|x)|x&y"}},
  {204, {'F', "y"}},
  {204, {'T', "y"}},
  {204, {'E', "y"}},
  {205, {'F', "(!x&!z|y)"}},
  {205, {'T', "(!x&!z|y)"}},
  {205, {'E', "!x&!z|y"}},
  {206, {'F', "(!x&z|y)"}},
  {206, {'T', "(!x&z|y)"}},
  {206, {'E', "!x&z|y"}},
  {207, {'F', "(!x|y)"}},
  {207, {'T', "(!x|y)"}},
  {207, {'E', "!x|y"}},
  {208, {'F', "!(!x|!y&z)"}},
  {208, {'T', "(!z|y)&x"}},
  {208, {'E', "!z&x|x&y"}},
  {209, {'F', "(!y&!z|x&y)"}},
  {209, {'T', "(!y&!z|x&y)"}},
  {209, {'E', "!y&!z|x&y"}},
  {210, {'F', "(!x&!y&z|!z&x|x&y)"}},
  {210, {'T', "!(!y&x&z)&(!y&z|x)"}},
  {210, {'E', "!x&!y&z|!z&x|x&y"}},
  {211, {'F', "!(!x&y|!y&x&z)"}},
  {211, {'T', "!(!x&y|!y&x&z)"}},
  {211, {'E', "!(x&z|y)|x&y"}},
  {212, {'F', "(!z&(x|y)|x&y)"}},
  {212, {'T', "(!z&(x|y)|x&y)"}},
  {212, {'E', "!z&(x|y)|x&y"}},
  {213, {'F', "(!z|x&y)"}},
  {213, {'T', "(!z|x&y)"}},
  {213, {'E', "!z|x&y"}},
  {214, {'F', "(!x&!y&z|!z&(x|y)|x&y)"}},
  {214, {'T', "(!x&!y&z|!z&(x|y)|x&y)"}},
  {214, {'E', "!x&!y&z|!z&(x|y)|x&y"}},
  {215, {'F', "(!x&!y|!z|x&y)"}},
  {215, {'T', "(!x&!y|!z|x&y)"}},
  {215, {'E', "!x&!y|!z|x&y"}},
  {216, {'F', "(!z&x|y&z)"}},
  {216, {'T', "(!z&x|y&z)"}},
  {216, {'E', "!z&x|y&z"}},
  {217, {'F', "!(!x&!z&y|!y&z)"}},
  {217, {'T', "!(!x&!z&y|!y&z)"}},
  {217, {'E', "!(!x&y|z)|y&z"}},
  {218, {'F', "!(!x&!z|!y&x&z)"}},
  {218, {'T', "!(!x&!z|!y&x&z)"}},
  {218, {'E', "!x&z|!z&x|x&y"}},
  {219, {'F', "(!x&!y|!z&x|y&z)"}},
  {219, {'T', "(!x&!y|!z&x|y&z)"}},
  {219, {'E', "!x&!y|!z&x|y&z"}},
  {220, {'F', "(!z&x|y)"}},
  {220, {'T', "(!z&x|y)"}},
  {220, {'E', "!z&x|y"}},
  {221, {'F', "(!z|y)"}},
  {221, {'T', "(!z|y)"}},
  {221, {'E', "!z|y"}},
  {222, {'F', "(!x&z|!z&x|y)"}},
  {222, {'T', "(!x&z|!z&x|y)"}},
  {222, {'E', "!x&z|!z&x|y"}},
  {223, {'F', "!(!y&x&z)"}},
  {223, {'T', "!(!y&x&z)"}},
  {223, {'E', "!x|!z|y"}},
  {224, {'F', "((y|z)&x)"}},
  {224, {'T', "(y|z)&x"}},
  {224, {'E', "(y|z)&x"}},
  {225, {'F', "(!(x|y|z)|(y|z)&x)"}},
  {225, {'T', "(!(x|y|z)|(y|z)&x)"}},
  {225, {'E', "!(x|y|z)|(y|z)&x"}},
  {226, {'F', "(!y&z|x&y)"}},
  {226, {'T', "(!y&z|x&y)"}},
  {226, {'E', "!y&z|x&y"}},
  {227, {'F', "!(!x&y|!y&!z&x)"}},
  {227, {'T', "!(!x&y|!y&!z&x)"}},
  {227, {'E', "!(!z&x|y)|x&y"}},
  {228, {'F', "(!z&y|x&z)"}},
  {228, {'T', "(!z&y|x&z)"}},
  {228, {'E', "!z&y|x&z"}},
  {229, {'F', "!(!x&z|!y&!z&x)"}},
  {229, {'T', "!(!x&z|!y&!z&x)"}},
  {229, {'E', "!(!y&x|z)|x&z"}},
  {230, {'F', "!(!x&y&z|!y&!z)"}},
  {230, {'T', "!(!x&y&z)&(y|z)"}},
  {230, {'E', "!y&z|!z&y|x&y"}},
  {231, {'F', "(!x&!y|!z&y|x&z)"}},
  {231, {'T', "(!x&!y|!z&y|x&z)"}},
  {231, {'E', "!x&!y|!z&y|x&z"}},
  {232, {'F', "((x|y)&z|x&y)"}},
  {232, {'T', "((x|y)&z|x&y)"}},
  {232, {'E', "(x|y)&z|x&y"}},
  {233, {'F', "(!(x|y|z)|(x|y)&z|x&y)"}},
  {233, {'T', "(!(x|y|z)|(x|y)&z|x&y)"}},
  {233, {'E', "!(x|y|z)|(x|y)&z|x&y"}},
  {234, {'F', "(x&y|z)"}},
  {234, {'T', "(x&y|z)"}},
  {234, {'E', "x&y|z"}},
  {235, {'F', "(!x&!y|x&y|z)"}},
  {235, {'T', "(!x&!y|x&y|z)"}},
  {235, {'E', "!x&!y|x&y|z"}},
  {236, {'F', "(x&z|y)"}},
  {236, {'T', "(x&z|y)"}},
  {236, {'E', "x&z|y"}},
  {237, {'F', "(!x&!z|x&z|y)"}},
  {237, {'T', "(!x&!z|x&z|y)"}},
  {237, {'E', "!x&!z|x&z|y"}},
  {238, {'F', "(y|z)"}},
  {238, {'T', "(y|z)"}},
  {238, {'E', "y|z"}},
  {239, {'F', "(!x|y|z)"}},
  {239, {'T', "(!x|y|z)"}},
  {239, {'E', "!x|y|z"}},
  {240, {'F', "x"}},
  {240, {'T', "x"}},
  {240, {'E', "x"}},
  {241, {'F', "(!y&!z|x)"}},
  {241, {'T', "(!y&!z|x)"}},
  {241, {'E', "!y&!z|x"}},
  {242, {'F', "(!y&z|x)"}},
  {242, {'T', "(!y&z|x)"}},
  {242, {'E', "!y&z|x"}},
  {243, {'F', "(!y|x)"}},
  {243, {'T', "(!y|x)"}},
  {243, {'E', "!y|x"}},
  {244, {'F', "(!z&y|x)"}},
  {244, {'T', "(!z&y|x)"}},
  {244, {'E', "!z&y|x"}},
  {245, {'F', "(!z|x)"}},
  {245, {'T', "(!z|x)"}},
  {245, {'E', "!z|x"}},
  {246, {'F', "(!y&z|!z&y|x)"}},
  {246, {'T', "(!y&z|!z&y|x)"}},
  {246, {'E', "!y&z|!z&y|x"}},
  {247, {'F', "!(!x&y&z)"}},
  {247, {'T', "!(!x&y&z)"}},
  {247, {'E', "!y|!z|x"}},
  {248, {'F', "(x|y&z)"}},
  {248, {'T', "(x|y&z)"}},
  {248, {'E', "x|y&z"}},
  {249, {'F', "(!y&!z|x|y&z)"}},
  {249, {'T', "(!y&!z|x|y&z)"}},
  {249, {'E', "!y&!z|x|y&z"}},
  {250, {'F', "(x|z)"}},
  {250, {'T', "(x|z)"}},
  {250, {'E', "x|z"}},
  {251, {'F', "(!y|x|z)"}},
  {251, {'T', "(!y|x|z)"}},
  {251, {'E', "!y|x|z"}},
  {252, {'F', "(x|y)"}},
  {252, {'T', "(x|y)"}},
  {252, {'E', "x|y"}},
  {253, {'F', "(!z|x|y)"}},
  {253, {'T', "(!z|x|y)"}},
  {253, {'E', "!z|x|y"}},
  {254, {'F', "(x|y|z)"}},
  {254, {'T', "(x|y|z)"}},
  {254, {'E', "x|y|z"}},
  {255, {'F', "(!x|x)"}},
  {255, {'T', "(!x|x)"}},
  {255, {'E', "!x|x"}},
};

map<int, string> result;

int main() {
  for (auto & it : wyniki) {
    if (it.second.first == 'E') {
      result[it.first] = it.second.second;
    }
  }
  int n;
  scanf("%d", &n);
  while (n--) {
    int maska = 0;
    for (int i = 0; i < 8; i++) {
      char c;
      scanf(" %c", &c);
      if (c == '1') {
        maska ^= (1 << i);
      }
    }
    printf("%s\n", result[maska].c_str());
  }
}
