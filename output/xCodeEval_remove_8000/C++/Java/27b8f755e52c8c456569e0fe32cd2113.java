import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

public class 27b8f755e52c8c456569e0fe32cd2113xcodeeval_processed_8000.json {
    public static String update(String s) {
        String result = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) - 'A' >= 0 && s.charAt(i) - 'A' < 26) {
                result += (char) (s.charAt(i) - 'A' + 'a');
            } else if (s.charAt(i) - 'a' >= 0 && s.charAt(i) - 'a' < 26) {
                result += s.charAt(i);
            }
        }
        return result;
    }

    public static Map<String, Integer> mp;
    public static Vector<Pair<Integer, String>> vt;

    public static String[] t1 = {
        "the",
        "said",
        "and",
        "bank",
        "market",
        "billion",
        "for",
        "stg",
        "mln",
        "with",
        "that",
        "march",
        "from",
        "money",
        "exchange",
        "currency",
        "had",
        "dollar",
        "its",
        "have",
        "will",
        "pct",
        "treasury",
        "but",
        "banks",
        "not",
        "bills",
        "would",
        "foreign",
        "was",
        "today",
        "this",
        "dlrs",
        "dealers",
        "which",
        "their",
        "system",
        "new",
        "central",
        "currencies",
        "they",
        "around",
        "monetary",
        "year",
        "were",
        "one",
        "rates",
        "markets",
        "liquidity",
        "japan",
        "dollars",
        "trading",
        "assistance",
        "are",
        "some",
        "has",
        "policy",
        "early",
        "against",
        "rate",
        "prices",
        "funds",
        "england",
        "more",
        "london",
        "last",
        "fed",
        "could",
        "baker",
        "after",
        "two",
        "told",
        "intervention",
        "help",
        "fall",
        "economic",
        "arab",
        "also",
        "yen",
        "while",
        "shortage",
        "securities",
        "other",
        "major",
        "commodity",
        "than",
        "paris",
        "option",
        "bundesbank",
        "bond",
        "trade",
        "states",
        "official",
        "now",
        "much",
        "house",
        "government",
        "far",
        "day",
        "bought"
    };

    public static int[] t1q = {
        575,
        162,
        148,
        83,
        67,
        64,
        63,
        59,
        57,
        54,
        54,
        53,
        52,
        48,
        48,
        47,
        45,
        45,
        42,
        42,
        41,
        40,
        35,
        35,
        34,
        33,
        33,
        32,
        32,
        31,
        30,
        28,
        28,
        28,
        27,
        26,
        26,
        25,
        25,
        24,
        23,
        23,
        22,
        21,
        21,
        21,
        20,
        20,
        20,
        20,
        20,
        19,
        19,
        19,
        18,
        18,
        17,
        17,
        17,
        16,
        16,
        16,
        16,
        15,
        15,
        15,
        15,
        15,
        15,
        15,
        14,
        14,
        14,
        14,
        14,
        14,
        14,
        14,
        13,
        13,
        13,
        13,
        13,
        13,
        13,
        12,
        12,
        12,
        12,
        12,
        11,
        11,
        11,
        11,
        11,
        11,
        11,
        11,
        11,
        11,
        11,
        11
    };

    public static String[] t2 = {
        "the",
        "billion",
        "dlrs",
        "pct",
        "and",
        "said",
        "rose",
        "from",
        "money",
        "mln",
        "bank",
        "january",
        "december",
        "february",
        "supply",
        "march",
        "fell",
        "year",
        "that",
        "was",
        "for",
        "week",
        "growth",
        "with",
        "reserve",
        "rise",
        "deposits",
        "after",
        "fed",
        "banks",
        "compared",
        "which",
        "loans",
        "federal",
        "end",
        "new",
        "ended",
        "adjusted",
        "were",
        "provisional",
        "november",
        "stg",
        "previous",
        "business",
        "plus",
        "last",
        "yearonyear",
        "treasury",
        "revised",
        "policy",
        "its",
        "balances",
        "seasonally",
        "reserves",
        "increase",
        "economists",
        "but",
        "average",
        "assets",
        "york",
        "this",
        "statement",
        "rises",
        "monetary",
        "data",
        "april",
        "total",
        "month",
        "six",
        "government",
        "deposit",
        "central",
        "canadian",
        "against",
        "about",
        "there",
        "rate",
        "period",
        "one",
        "not",
        "measure",
        "latest",
        "had",
        "grew",
        "earlier",
        "currency",
        "chartered",
        "would",
        "singapore",
        "sector",
        "net",
        "has",
        "funds",
        "fall",
        "while",
        "weeks",
        "two",
        "showed",
        "savings",
        "foreign"
    };

    public static int[] t2q = {
        429,
        285,
        225,
        220,
        145,
        112,
        109,
        102,
        94,
        91,
        89,
        76,
        73,
        71,
        69,
        69,
        65,
        58,
        49,
        48,
        48,
        47,
        45,
        44,
        40,
        39,
        32,
        32,
        31,
        31,
        30,
        26,
        25,
        25,
        25,
        23,
        23,
        23,
        22,
        22,
        22,
        20,
        20,
        20,
        19,
        19,
        18,
        18,
        18,
        18,
        18,
        18,
        17,
        17,
        17,
        17,
        17,
        17,
        17,
        16,
        16,
        16,
        16,
        16,
        16,
        16,
        15,
        15,
        14,
        14,
        14,
        14,
        14,
        14,
        14,
        13,
        13,
        13,
        13,
