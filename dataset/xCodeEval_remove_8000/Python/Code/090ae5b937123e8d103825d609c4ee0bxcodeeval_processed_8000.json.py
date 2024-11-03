num = int(input())
res = []
factors = [{1}, {1, 2}, {1, 3}, {1, 2}, {1, 5}, {1, 2, 3}, {1, 7}, {1, 2}, {1, 3}, {1, 2, 5}, {1, 11}, {1, 2, 3}, {1, 13}, {1, 2, 7}, {1, 3, 5}, {1, 2}, {1, 17}, {1, 2, 3}, {1, 19}, {1, 2, 5}, {1, 3, 7}, {1, 2, 11}, {1, 23}, {1, 2, 3}, {1, 5}, {1, 2, 13}, {1, 3}, {1, 2, 7}, {1, 29}, {1, 2, 3, 5}, {1, 31}, {1, 2}, {3, 1, 11}, {1, 2, 17}, {1, 5, 7}, {1, 2, 3}, {1, 37}, {1, 2, 19}, {1, 3, 13}, {1, 2, 5}, {1, 41}, {1, 2, 3, 7}, {1, 43}, {1, 2, 11}, {1, 3, 5}, {1, 2, 23}, {1, 47}, {1, 2, 3}, {1, 7}, {1, 2, 5}, {1, 3, 17}, {1, 2, 13}, {1, 53}, {1, 2, 3}, {1, 11, 5}, {1, 2, 7}, {3, 1, 19}, {1, 2, 29}, {1, 59}, {1, 2, 3, 5}, {1, 61}, {1, 2, 31}, {1, 3, 7}, {1, 2}, {1, 5, 13}, {3, 1, 2, 11}, {1, 67}, {1, 2, 17}, {1, 3, 23}, {1, 2, 5, 7}, {1, 71}, {1, 2, 3}, {73, 1}, {1, 2, 37}, {1, 3, 5}, {1, 2, 19}, {1, 11, 7}, {1, 2, 3, 13}, {1, 79}, {1, 2, 5}, {1, 3}, {1, 2, 41}, {1, 83}, {1, 2, 3, 7}, {1, 5, 17}, {1, 2, 43}, {1, 3, 29}, {1, 2, 11}, {89, 1}, {1, 2, 3, 5}, {1, 13, 7}, {1, 2, 23}, {1, 3, 31}, {1, 2, 47}, {1, 19, 5}, {1, 2, 3}, {1, 97}, {1, 2, 7}, {3, 1, 11}, {1, 2, 5}, {1, 101}, {1, 2, 3, 17}, {1, 103}, {1, 2, 13}, {1, 3, 5, 7}, {1, 2, 53}, {1, 107}, {1, 2, 3}, {1, 109}, {1, 2, 11, 5}, {1, 3, 37}, {1, 2, 7}, {1, 113}, {3, 1, 2, 19}, {1, 5, 23}, {1, 2, 29}, {1, 3, 13}, {1, 2, 59}, {1, 17, 7}, {1, 2, 3, 5}, {1, 11}, {1, 2, 61}, {1, 3, 41}, {1, 2, 31}, {1, 5}, {1, 2, 3, 7}, {1, 127}, {1, 2}, {3, 1, 43}, {1, 2, 5, 13}, {1, 131}, {3, 1, 2, 11}, {1, 19, 7}, {1, 2, 67}, {1, 3, 5}, {1, 2, 17}, {1, 137}, {1, 2, 3, 23}, {1, 139}, {1, 2, 5, 7}, {1, 3, 47}, {1, 2, 71}, {1, 11, 13}, {1, 2, 3}, {1, 5, 29}, {73, 1, 2}, {1, 3, 7}, {1, 2, 37}, {1, 149}, {1, 2, 3, 5}, {1, 151}, {1, 2, 19}, {1, 3, 17}, {1, 2, 11, 7}, {1, 5, 31}, {1, 2, 3, 13}, {1, 157}, {1, 2, 79}, {1, 3, 53}, {1, 2, 5}, {1, 7, 23}, {1, 2, 3}, {1, 163}, {1, 2, 41}, {3, 1, 11, 5}, {1, 2, 83}, {1, 167}, {1, 2, 3, 7}, {1, 13}, {1, 2, 5, 17}, {3, 1, 19}, {1, 2, 43}, {1, 173}, {1, 2, 3, 29}, {1, 5, 7}, {1, 2, 11}, {3, 1, 59}, {89, 1, 2}, {1, 179}, {1, 2, 3, 5}, {1, 181}, {1, 2, 13, 7}, {1, 3, 61}, {1, 2, 23}, {1, 5, 37}, {1, 2, 3, 31}, {1, 11, 17}, {1, 2, 47}, {1, 3, 7}, {1, 2, 19, 5}, {1, 191}, {1, 2, 3}, {1, 193}, {1, 2, 97}, {1, 5, 3, 13}, {1, 2, 7}, {1, 197}, {3, 1, 2, 11}, {1, 199}, {1, 2, 5}, {3, 1, 67}, {1, 2, 101}, {1, 29, 7}, {1, 2, 3, 17}, {1, 5, 41}, {1, 2, 103}, {1, 3, 23}, {1, 2, 13}, {11, 1, 19}, {1, 2, 3, 5, 7}, {1, 211}, {1, 2, 53}, {1, 3, 71}, {1, 2, 107}, {1, 43, 5}, {1, 2, 3}, {1, 7, 31}, {1, 2, 109}, {73, 1, 3}, {1, 2, 11, 5}, {1, 13, 17}, {1, 2, 3, 37}, {1, 223}, {1, 2, 7}, {1, 3, 5}, {1, 2, 113}, {1, 227}, {3, 1, 2, 19}, {1, 229}, {1, 2, 5, 23}, {3, 1, 11, 7}, {1, 2, 29}, {1, 233}, {1, 2, 3, 13}, {1, 5, 47}, {1, 2, 59}, {1, 3, 79}, {1, 2, 17, 7}, {1, 239}, {1, 2, 3, 5}, {1, 241}, {1, 2, 11}, {1, 3}, {1, 2, 61}, {1, 5, 7}, {1, 2, 3, 41}, {1, 19, 13}, {1, 2, 31}, {3, 1, 83}, {1, 2, 5}, {1, 251}, {1, 2, 3, 7}, {1, 11, 23}, {1, 2, 127}, {1, 3, 5, 17}, {1, 2}, {1, 257}, {3, 1, 2, 43}, {1, 37, 7}, {1, 2, 5, 13}, {1, 3, 29}, {1, 2, 131}, {1, 263}, {3, 1, 2, 11}, {1, 5, 53}, {1, 2, 19, 7}, {89, 1, 3}, {1, 2, 67}, {1, 269}, {1, 2, 3, 5}, {1, 271}, {1, 2, 17}, {1, 3, 13, 7}, {1, 137, 2}, {1, 11, 5}, {1, 2, 3, 23}, {1, 277}, {1, 2, 139}, {1, 3, 31}, {1, 2, 5, 7}, {1, 281}, {1, 2, 3, 47}, {1, 283}, {1, 2, 71}, {3, 1, 19, 5}, {1, 2, 11, 13}, {1, 7, 41}, {1, 2, 3}, {1, 17}, {1, 2, 5, 29}, {1, 3, 97}, {73, 1, 2}, {1, 293}, {1, 2, 3, 7}, {1, 59, 5}, {1, 2, 37}, {3, 1, 11}, {1, 2, 149}, {1, 13, 23}, {1, 2, 3, 5}, {1, 43, 7}, {1, 2, 151}, {1, 3, 101}, {1, 2, 19}, {1, 5, 61}, {1, 2, 3, 17}, {1, 307}, {1, 2, 11, 7}, {1, 3, 103}, {1, 2, 5, 31}, {1, 311}, {1, 2, 3, 13}, {1, 313}, {1, 2, 157}, {1, 3, 5, 7}, {1, 2, 79}, {1, 317}, {1, 2, 3, 53}, {1, 11, 29}, {1, 2, 5}, {3, 1, 107}, {1, 2, 7, 23}, {1, 19, 17}, {1, 2, 3}, {1, 5, 13}, {1, 2, 163}, {1, 3, 109}, {1, 2, 41}, {1, 7, 47}, {1, 2, 3, 5, 11}, {1, 331}, {1, 2, 83}, {1, 3, 37}, {1, 2, 167}, {1, 67, 5}, {1, 2, 3, 7}, {337, 1}, {1, 2, 13}, {1, 3, 113}, {1, 2, 5, 17}, {1, 11, 31}, {3, 1, 2, 19}, {1, 7}, {1, 2, 43}, {1, 3, 5, 23}, {1, 2, 173}, {1, 347}, {1, 2, 3, 29}, {1, 349}, {1, 2, 5, 7}, {1, 3, 13}, {1, 2, 11}, {1, 353}, {3, 1, 2, 59}, {1, 5, 71}, {89, 1, 2}, {1, 3, 17, 7}, {1, 2, 179}, {1, 359}, {1, 2, 3, 5}, {1, 19}, {1, 2, 181}, {3, 1, 11}, {1, 2, 13, 7}, {73, 1, 5}, {1, 2, 3, 61}, {1, 367}, {1, 2, 23}, {1, 3, 41}, {1, 2, 5, 37}, {1, 53, 7}, {1, 2, 3, 31}, {1, 373}, {1, 2, 11, 17}, {1, 3, 5}, {1, 2, 47}, {1, 13, 29}, {1, 2, 3, 7}, {1, 379}, {1, 2, 19, 5}, {1, 3, 127}, {1, 2, 191}, {1, 383}, {1, 2, 3}, {1, 11, 5, 7}, {1, 2, 193}, {3, 1, 43}, {1, 2, 97}, {1, 389}, {1, 2, 3, 5, 13}, {1, 17, 23}, {1, 2, 7}, {1, 3, 131}, {1, 2, 197}, {1, 5, 79}, {3, 1, 2, 11}, {1, 397}, {1, 2, 199}, {3, 1, 19, 7}, {1, 2, 5}, {1, 401}, {3, 1, 2, 67}, {1, 13, 31}, {1, 2, 101}, {1, 3, 5}, {1, 2, 29, 7}, {1, 11, 37}, {1, 2, 3, 17}, {1, 409}, {1, 2, 5, 41}, {1, 137, 3}, {1, 2, 103}, {1, 59, 7}, {1, 2, 3, 23}, {1, 83, 5}, {1, 2, 13}, {1, 3, 139}, {11, 1, 2, 19}, {1, 419}, {1, 2, 3, 5, 7}, {1, 421}, {1, 2, 211}, {1, 3, 47}, {1, 2, 53}, {1, 5, 17}, {1, 2, 3, 71}, {1, 61, 7}, {1, 2, 107}, {3, 1, 11, 13}, {1, 2, 43, 5}, {1, 431}, {1, 2, 3}, {1, 433}, {1, 2, 7, 31}, {1, 5, 3, 29}, {1, 2, 109}, {1, 19, 23}, {73, 1, 2, 3}, {1, 439}, {1, 2, 11, 5}, {1, 3, 7}, {1, 2, 13, 17}, {1, 443}, {1, 2, 3, 37}, {89, 1, 5}, {1, 2, 223}, {1, 3, 149}, {1, 2, 7}, {1, 449}, {1, 2, 3, 5}, {1, 11, 41}, {1, 2, 113}, {1, 3, 151}, {1, 2, 227}, {1, 5, 13, 7}, {3, 1, 2, 19}, {1, 457}, {1, 2, 229}, {1, 3, 17}, {1, 2, 5, 23}, {1, 461}, {1, 2, 3, 7, 11}, {1, 463}, {1, 2, 29}, {1, 3, 5, 31}, {1, 2, 233}, {1, 467}, {1, 2, 3, 13}, {1, 67, 7}, {1, 2, 5, 47}, {1, 3, 157}, {1, 2, 59}, {11, 1, 43}, {1, 2, 3, 79}, {1, 19, 5}, {1, 2, 17, 7}, {1, 3, 53}, {1, 2, 239}, {1, 479}, {1, 2, 3, 5}, {1, 13, 37}, {1, 2, 241}, {1, 3, 7, 23}, {1, 2, 11}, {1, 5, 97}, {1, 2, 3}, {1, 487}, {1, 2, 61}, {1, 3, 163}, {1, 2, 5, 7}, {1, 491}, {1, 2, 3, 41}, {1, 29, 17}, {1, 2, 19, 13}, {3, 1, 11, 5}, {1, 2, 31}, {1, 7, 71}, {3, 1, 2, 83}, {1, 499}, {1, 2, 5}, {1, 3, 167}, {1, 2, 251}, {1, 503}, {1, 2, 3, 7}, {1, 5, 101}, {1, 2, 11, 23}, {1, 3, 13}, {1, 2, 127}, {1, 509}, {1, 2, 3, 5, 17}, {73, 1, 7}, {1, 2}, {3, 1, 19}, {1, 2, 257}, {1, 5, 103}, {3, 1, 2, 43}, {1, 11, 47}, {1, 2, 37, 7}, {1, 3, 173}, {1, 2, 5, 13}, {1, 521}, {1, 2, 3, 29}, {1, 523}, {1, 2, 131}, {1, 3, 5, 7}, {1, 2, 263}, {1, 17, 31}, {3, 1, 2, 11}, {1, 23}, {1, 2, 5, 53}, {3, 1, 59}, {1, 2, 19, 7}, {1, 13, 41}, {89, 1, 2, 3}, {1, 107, 5}, {1, 2, 67}, {1, 3, 179}, {1, 2, 269}, {1, 11, 7}, {1, 2, 3, 5}, {1, 541}, {1, 2, 271}, {1, 3, 181}, {1, 2, 17}, {1, 5, 109}, {1, 2, 3, 7, 13}, {1, 547}, {1, 137, 2}, {1, 3, 61}, {1, 2, 11, 5}, {1, 19, 29}, {1, 2, 3, 23}, {1, 7, 79}, {1, 2, 277}, {1, 5, 3, 37}, {1, 2, 139}, {1, 557}, {1, 2, 3, 31}, {1, 43, 13}, {1, 2, 5, 7}, {3, 1, 11, 17}, {1, 2, 281}, {1, 563}, {1, 2, 3, 47}, {1, 5, 113}, {1, 2, 283}, {1, 3, 7}, {1, 2, 71}, {1, 569}, {1, 2, 3, 5, 19}, {1, 571}, {1, 2, 11, 13}, {1, 3, 191}, {1, 2, 7, 41}, {1, 5, 23}, {1, 2, 3}, {577, 1}, {1, 2, 17}, {1, 3, 193}, {1, 2, 5, 29}, {1, 83, 7}, {1, 2, 3, 97}, {1, 11, 53}, {73, 1, 2}, {1, 5, 3, 13}, {1, 2, 293}, {1, 587}, {1, 2, 3, 7}, {1, 19, 31}, {1, 2, 59, 5}, {1, 3, 197}, {1, 2, 37}, {593, 1}, {3, 1, 2, 11}, {1, 5, 17, 7}, {1, 2, 149}, {1, 3, 199}, {1, 2, 13, 23}, {1, 599}, {1, 2, 3, 5}, {601, 1}, {1, 2, 43, 7}, {3, 1, 67}, {1, 2, 151}, {1, 11, 5}, {1, 2, 3, 101}, {1, 607}, {1, 2, 19}, {1, 3, 29, 7}, {1, 2, 5, 61}, {1, 13, 47}, {1, 2, 3, 17}, {1, 613}, {1, 2, 307}, {1, 3, 5, 41}, {1, 2, 11, 7}, {1, 617}, {1, 2, 3, 103}, {1, 619}, {1, 2, 5, 31}, {1, 3, 23}, {1, 2, 311}, {89, 1, 7}, {1, 2, 3, 13}, {1, 5}, {1, 2, 313}, {19, 1, 11, 3}, {1, 2, 157}, {1, 37, 17}, {1, 2, 3, 5, 7}, {1, 631}, {1, 2, 79}, {1, 3, 211}, {1, 2, 317}, {1, 5, 127}, {1, 2, 3, 53}, {1, 13, 7}, {1, 2, 11, 29}, {1, 3, 71}, {1, 2, 5}, {1, 641}, {3, 1, 2, 107}, {1, 643}, {1, 2, 7, 23}, {3, 1, 43, 5}, {1, 2, 19, 17}, {1, 647}, {1, 2, 3}, {11, 1, 59}, {1, 2, 5, 13}, {1, 3, 7, 31}, {1, 2, 163}, {1, 653}, {1, 2, 3, 109}, {1, 131, 5}, {1, 2, 41}, {73, 1, 3}, {1, 2, 7, 47}, {1, 659}, {1, 2, 3, 5, 11}, {1, 661}, {1, 2, 331}, {1, 3, 13, 17}, {1, 2, 83}, {1, 19, 5, 7}, {1, 2, 3, 37}, {1, 29, 23}, {1, 2, 167}, {1, 3, 223}, {1, 2, 67, 5}, {1, 11, 61}, {1, 2, 3, 7}, {1, 673}, {337, 1, 2}, {1, 3, 5}, {1, 2, 13}, {1, 677}, {1, 2, 3, 113}, {1, 97, 7}, {1, 2, 5, 17}, {1, 3, 227}, {1, 2, 11, 31}, {1, 683}, {3, 1, 2, 19}, {1, 137, 5}, {1, 2, 7}, {1, 3, 229}, {1, 2, 43}, {1, 13, 53}, {1, 2, 3, 5, 23}, {1, 691}, {1, 2, 173}, {3, 1, 11, 7}, {1, 2, 347}, {1, 139, 5}, {1, 2, 3, 29}, {1, 17, 41}, {1, 2, 349}, {1, 3, 233}, {1, 2, 5, 7}, {1, 701}, {1, 2, 3, 13}, {1, 19, 37}, {1, 2, 11}, {1, 3, 5, 47}, {1, 2, 353}, {1, 101, 7}, {3, 1, 2, 59}, {1, 709}, {1, 2, 5, 71}, {1, 3, 79}, {89, 1, 2}, {1, 23, 31}, {1, 2, 3, 7, 17}, {1, 5, 11, 13}, {1, 2, 179}, {1, 3, 239}, {1, 2, 359}, {1, 719}, {1, 2, 3, 5}, {1, 7, 103}, {1, 2, 19}, {1, 3, 241}, {1, 2, 181}, {1, 5, 29}, {3, 1, 2, 11}, {1, 727}, {1, 2, 13, 7}, {1, 3}, {73, 1, 2, 5}, {1, 43, 17}, {1, 2, 3, 61}, {1, 733}, {1, 2, 367}, {1, 3, 5, 7}, {1, 2, 23}, {11, 1, 67}, {1, 2, 3, 41}, {1, 739}, {1, 2, 5, 37}, {3, 1, 19, 13}, {1, 2, 53, 7}, {1, 743}, {1, 2, 3, 31}, {1, 5, 149}, {1, 2, 373}, {3, 1, 83}, {1, 2, 11, 17}, {1, 107, 7}, {1, 2, 3, 5}, {1, 751}, {1, 2, 47}, {1, 3, 251}, {1, 2, 13, 29}, {1, 5, 151}, {1, 2, 3, 7}, {1, 757}, {1, 2, 379}, {3, 1, 11, 23}, {1, 2, 19, 5}, {1, 761}, {1, 2, 3, 127}, {1, 109, 7}, {1, 2, 191}, {1, 3, 5, 17}, {1, 2, 383}, {1, 59, 13}, {1, 2, 3}, {1, 769}, {1, 2, 5, 7, 11}, {1, 3, 257}, {1, 2, 193}, {1, 773}, {3, 1, 2, 43}, {1, 5, 31}, {1, 2, 97}, {1, 3, 37, 7}, {1, 2, 389}, {1, 19, 41}, {1, 2, 3, 5, 13}, {1, 11, 71}, {1, 2, 17, 23}, {1, 3, 29}, {1, 2, 7}, {1, 5, 157}, {1, 2, 3, 131}, {1, 787}, {1, 2, 197}, {1, 3, 263}, {1, 2, 5, 79}, {1, 113, 7}, {3, 1, 2, 11}, {1, 13, 61}, {1, 2, 397}, {1, 5, 3, 53}, {1, 2, 199}, {1, 797}, {1, 2, 3, 7, 19}, {1, 17, 47}, {1, 2, 5}, {89, 1, 3}, {1, 401, 2}, {73, 1, 11}, {3, 1, 2, 67}, {1, 7, 5, 23}, {1, 2, 13, 31}, {1, 3, 269}, {1, 2, 101}, {1, 809}, {1, 2, 3, 5}, {1, 811}, {1, 2, 29, 7}, {1, 3, 271}, {1, 2, 11, 37}, {1, 163, 5}, {1, 2, 3, 17}, {19, 1, 43}, {1, 409, 2}, {1, 3, 13, 7}, {1, 2, 5, 41}, {1, 821}, {3, 1, 137, 2}, {1, 823}, {1, 2, 103}, {3, 1, 11, 5}, {1, 2, 59, 7}, {1, 827}, {1, 2, 3, 23}, {1, 829}, {1, 2, 83, 5}, {1, 3, 277}, {1, 2, 13}, {1, 17, 7}, {1, 2, 3, 139}, {1, 5, 167}, {11, 1, 2, 19}, {1, 3, 31}, {1, 2, 419}, {1, 839}, {1, 2, 3, 5, 7}, {1, 29}, {1, 2, 421}, {1, 3, 281}, {1, 2, 211}, {1, 5, 13}, {1, 2, 3, 47}, {1, 11, 7}, {1, 2, 53}, {3, 1, 283}, {1, 2, 5, 17}, {1, 37, 23}, {1, 2, 3, 71}, {1, 853}, {1, 2, 61, 7}, {3, 1, 19, 5}, {1, 2, 107}, {857, 1}, {1, 2, 3, 11, 13}, {1, 859}, {1, 2, 43, 5}, {1, 3, 7, 41}, {1, 2, 431}, {1, 863}, {1, 2, 3}, {1, 5, 173}, {1, 2, 433}, {1, 3, 17}, {1, 2, 7, 31}, {1, 11, 79}, {1, 2, 3, 5, 29}, {1, 67, 13}, {1, 2, 109}, {1, 3, 97}, {1, 2, 19, 23}, {1, 5, 7}, {73, 1, 2, 3}, {1, 877}, {1, 2, 439}, {1, 3, 293}, {1, 2, 11, 5}, {1, 881}, {1, 2, 3, 7}, {1, 883}, {1, 2, 13, 17}, {3, 1, 59, 5}, {1, 2, 443}, {1, 887}, {1, 2, 3, 37}, {1, 7, 127}, {89, 1, 2, 5}, {3, 1, 11}, {1, 2, 223}, {1, 19, 47}, {1, 2, 3, 149}, {1, 179, 5}, {1, 2, 7}, {1, 3, 13, 23}, {1, 2, 449}, {1, 29, 31}, {1, 2, 3, 5}, {1, 53, 17}, {1, 2, 11, 41}, {3, 1, 43, 7}, {1, 2, 113}, {1, 5, 181}, {1, 2, 3, 151}, {1, 907}, {1, 2, 227}, {1, 3, 101}, {1, 2, 5, 7, 13}, {1, 911}, {3, 1, 2, 19}, {11, 1, 83}, {1, 2, 457}, {1, 5, 3, 61}, {1, 2, 229}, {1, 131, 7}, {1, 2, 3, 17}, {1, 919}, {1, 2, 5, 23}, {3, 1, 307}, {1, 2, 461}, {1, 13, 71}, {1, 2, 3, 7, 11}, {1, 5, 37}, {1, 2, 463}, {1, 3, 103}, {1, 2, 29}, {1, 929}, {1, 2, 3, 5, 31}, {1, 19, 7}, {1, 2, 233}, {1, 3, 311}, {1, 2, 467}, {1, 11, 5, 17}, {1, 2, 3, 13}, {1, 937}, {1, 2, 67, 7}, {1, 3, 313}, {1, 2, 5, 47}, {1, 941}, {1, 2, 3, 157}, {1, 23, 41}, {1, 2, 59}, {1, 3, 5, 7}, {11, 1, 2, 43}, {1, 947}, {1, 2, 3, 79}, {73, 1, 13}, {1, 2, 19, 5}, {1, 3, 317}, {1, 2, 17, 7}, {1, 953}, {1, 2, 3, 53}, {1, 5, 191}, {1, 2, 239}, {3, 1, 11, 29}, {1, 2, 479}, {1, 137, 7}, {1, 2, 3, 5}, {1, 31}, {1, 2, 13, 37}, {3, 1, 107}, {1, 2, 241}, {1, 193, 5}, {1, 2, 3, 7, 23}, {1, 967}, {1, 2, 11}, {3, 1, 19, 17}, {1, 2, 5, 97}, {1, 971}, {1, 2, 3}, {1, 139, 7}, {1, 2, 487}, {1, 5, 3, 13}, {1, 2, 61}, {1, 977}, {1, 2, 3, 163}, {89, 1, 11}, {1, 2, 5, 7}, {1, 3, 109}, {1, 2, 491}, {1, 983}, {1, 2, 3, 41}, {1, 5, 197}, {1, 2, 29, 17}, {1, 3, 7, 47}, {1, 2, 19, 13}, {1, 43, 23}, {1, 2, 3, 5, 11}, {1, 991}, {1, 2, 31}, {3, 1, 331}, {1, 2, 7, 71}, {1, 5, 199}, {3, 1, 2, 83}, {1, 997}, {1, 2, 499}, {1, 3, 37}, {1, 2, 5}] 
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387, 5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791, 5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939, 5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133, 6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221, 6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919, 7927, 7933, 7937, 7949, 7951, 7963, 7993, 8009, 8011, 8017, 8039, 8053, 8059, 8069, 8081, 8087, 8089, 8093, 8101, 8111, 8117, 8123, 8147, 8161, 8167, 8171, 8179, 8191, 8209, 8219, 8221, 8231, 8233, 8237, 8243, 8263, 8269, 8273, 8287, 8291, 8293, 8297, 8311, 8317, 8329, 8353, 8363, 8369, 8377, 8387, 8389, 8419, 8423, 8429, 8431, 8443, 8447, 8461, 8467, 8501, 8513, 8521, 8527, 8537, 8539, 8543, 8563, 8573, 8581, 8597, 8599, 8609, 8623, 8627, 8629, 8641, 8647, 8663, 8669, 8677, 8681, 8689, 8693, 8699, 8707, 8713, 8719, 8731, 8737, 8741, 8747, 8753, 8761, 8779, 8783, 8803, 8807, 8819, 8821, 8831, 8837, 8839, 8849, 8861, 8863, 8867, 8887, 8893, 8923, 8929, 8933, 8941, 8951, 8963, 8969, 8971, 8999, 9001, 9007, 9011, 9013, 9029, 9041, 9043, 9049, 9059, 9067, 9091, 9103, 9109, 9127, 9133, 9137, 9151, 9157, 9161, 9173, 9181, 9187, 9199, 9203, 9209, 9221, 9227, 9239, 9241, 9257, 9277, 9281, 9283, 9293, 9311, 9319, 9323, 9337, 9341, 9343, 9349, 9371, 9377, 9391, 9397, 9403, 9413, 9419, 9421, 9431, 9433, 9437, 9439, 9461, 9463, 9467, 9473, 9479, 9491, 9497, 9511, 9521, 9533, 9539, 9547, 9551, 9587, 9601, 9613, 9619, 9623, 9629, 9631, 9643, 9649, 9661, 9677, 9679, 9689, 9697, 9719, 9721, 9733, 9739, 9743, 9749, 9767, 9769, 9781, 9787, 9791, 9803, 9811, 9817, 9829, 9833, 9839, 9851, 9857, 9859, 9871, 9883, 9887, 9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973]
 
 
def id0(x, y):
    return factors[x - 1] & factors[y - 1] == {1}
 
def sn(n, l):
    r = list(range(l))[::-1]
    m = []
    for a1 in r:
        c = n - a1
        if a1 >= c and c >= 0:
            m.append((a1,c))
 
    return m
 
 
def srange(l):
    g = 2 * l - 1
    for i in reversed(range(g)):
        for elem in sn(i, l):
            yield elem
 
 
for _ in range(num):
    b = int(input())
    l = list(map(int, input().split(" ")))
    inds = {}
    for i, elem in enumerate(l):
        if elem not in inds:
            inds[elem] = 0
        inds[elem] = i
        
    rl = l[::-1]
    sl = list(set(l))
    xi = -1

    for x1, x2 in srange(len(sl)):
        a1 = sl[x1]
        b1 = sl[x2]
        if id0(a1, b1 ):
                xi = max(inds[a1] + inds[b1] + 2, xi)
    
    print(xi)