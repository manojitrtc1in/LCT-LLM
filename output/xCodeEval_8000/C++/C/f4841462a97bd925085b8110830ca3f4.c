#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define CHUNK_SIZE 100000

int A[] = { 0,
4784, 8978, 12981, 16901, 20732, 24523, 28249, 31916, 35585, 39176, 42818, 46430, 49962, 53516, 57023, 60523, 64040, 67489, 70985, 74417, 77879, 81285, 84679, 88055, 91433, 94878, 98240, 101608, 104979, 108284, 111653, 115039, 118375, 121695, 124997, 128270, 131626, 134912, 138219, 141503, 144830, 148121, 151368, 154619, 157925, 161166, 164444, 167675, 170946, 174194, 177433, 180617, 183844, 187048, 190283, 193493, 196709, 199900, 203111, 206333, 209526, 212732, 215966, 219123, 222272, 225463, 228651, 231844, 235069, 238261, 241443, 244581, 247733, 250868, 253974, 257141, 260352, 263482, 266623, 269760, 272885, 276014, 279149, 282271, 285396, 288556, 291710, 294878, 297984, 301101, 304177, 307326, 310444, 313579, 316642, 319813, 322904, 326007, 329106, 332181,
335268, 338394, 341465, 344551, 347665, 350739, 353840, 356909, 360000, 363080, 366160, 369261, 372328, 375439, 378518, 381635, 384728, 387817, 390920, 393993, 397033, 400087, 403209, 406288, 409309, 412333, 415431, 418499, 421556, 424569, 427583, 430660, 433680, 436753, 439791, 442818, 445857, 448901, 451962, 454974, 457972, 461015, 464069, 467135, 470153, 473178, 476215, 479250, 482265, 485275, 488279, 491293, 494311, 497242, 500236, 503251, 506276, 509308, 512383, 515414, 518404, 521398, 524428, 527422, 530472, 533469, 536442, 539450, 542467, 545501, 548499, 551461, 554513, 557493, 560489, 563514, 566514, 569508, 572481, 575503, 578464, 581445, 584484, 587448, 590416, 593357, 596373, 599365, 602379, 605357, 608340, 611346, 614316, 617284, 620283, 623219, 626204, 629187, 632137, 635171,
