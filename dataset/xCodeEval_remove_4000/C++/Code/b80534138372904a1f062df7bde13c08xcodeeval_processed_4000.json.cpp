
using namespace std;


    

    






typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 1e3 + 15;
const int Q = 1e9 + 7;


int mask[M];
int in[20][M];
int res[20][M];
bool ign[20];

vector<int> good = {142286, 107742, 111389, 187470, 188296, 92398, 56718, 113739, 81332, 207800, 48938, 93418, 4023, 190124, 91035, 77479, 27439, 94708, 180974, 138611, 40286, 153460, 173798, 103292, 178478, 166267, 22223, 182518, 78585, 70643, 111827, 44977, 156015, 109779, 11983, 153150, 133999, 178358, 122036, 140766, 206817, 160218, 93874, 76638, 115550, 36559, 173662, 177231, 203235, 146011, 77421, 162446, 173847, 71095, 156379, 79086, 43950, 62013, 89739, 121955, 88981, 31445, 18939, 64015, 43757, 120037, 23390, 32652, 61154, 60085, 59114, 150477, 97121, 4092, 183891, 114449, 150899, 109372, 42455, 144364, 80364, 192791, 203039, 81617, 126730, 88564, 166799, 151155, 199867, 188004, 140247, 126164, 128652, 151522, 82399, 71417, 153966, 124506, 30389, 179283, 188016, 85876, 202108, 118676, 28270, 96828, 67451, 101207, 128232, 23742, 87955, 198319, 145137, 143203, 187015, 147122, 147400, 117965, 110134, 89675, 61044, 86335, 106097, 112757, 148474, 93327, 117477, 173802, 176743, 115446, 120614, 187164, 192290, 119768, 13727, 181431, 64651, 109417, 24291, 157369, 108894, 115692, 183126, 163649, 74733, 63174, 188535, 101843, 105418, 188668, 157145, 186471, 110392, 39879, 75701, 32053, 91367, 19949, 67517, 64330, 137943, 83932, 161009, 118046, 167404, 154982, 201685, 39922, 174301, 175046, 157532, 89329, 145299, 194136, 118329, 176618, 38590, 60249, 171067, 112828, 104822, 46902, 171669, 141046, 189798, 185257, 118414, 116645, 138218, 36087, 125703, 166587, 176604, 13151, 191216, 70638, 14059, 65224, 174570, 123671, 76407, 30442, 122444, 125353, 153850, 20189, 121257, 157467, 159464, 32092, 63705, 22895, 87988, 104937, 103143, 156405, 99279, 72557, 107987, 35551, 122406, 113512, 187336, 79578, 179341, 146138, 62095, 198303, 111949, 45693, 195458, 55094, 184225, 196108, 175261, 187234, 70847, 10079, 124505, 166859, 90543, 103913, 181971, 127882, 207271, 111558, 158172, 13757, 113052, 202172, 73148, 122005, 99935, 150955, 25533, 127728, 161433, 73367, 157275, 156153, 19452, 178475, 59165, 174765, 103131, 38631, 145719, 42741, 58063, 129921, 141019, 32496, 186541, 172407, 43507, 178581, 103646, 117933, 55723, 76743, 85454, 156922, 29658, 169781, 137973, 146325, 85429, 44277, 62158, 203373, 82926, 188653, 173630, 89497, 175466, 207533, 106253, 79191, 40605, 89996, 116633, 22514, 55479, 138599, 183641, 175383, 110500, 178144, 167371, 85707, 167788, 195346, 165111, 60761, 186579, 14321, 162033, 200625, 87229, 62681, 153270, 189626, 189643, 59878, 204596, 61033, 96038, 44966, 32154, 72566, 54190, 194448, 85481, 52963, 32225, 207796, 114072, 42923, 55899, 186796, 87962, 60326, 171342, 73319, 73331, 77621, 134007, 174034, 118182, 150396, 47011, 199911, 45775, 60028, 64713, 129603, 207165, 119501, 202609, 89510, 56938, 176822, 155105, 121118, 200523, 79545, 138204, 159576, 142055, 101227, 117023, 129411, 137709, 11899, 204258, 78239, 8135, 159188, 23795, 187217, 177183, 92525, 62285, 52335, 73611, 32058, 7102, 76911, 95566, 183154, 3837, 125261, 61345, 170716, 107919, 28026, 186833, 76278, 102055, 12022, 171222, 94925, 123253, 177624, 61013, 38743, 116682, 176539, 172639, 92397, 200587, 91892, 156894, 52922, 108390, 114815, 104909, 168847, 169891, 171378, 181054, 92627, 88553, 114084, 81039, 4071, 39787, 163265, 158315, 118179, 126066, 191660, 44908, 168190, 89545, 162108, 194710, 95090, 188959, 108958, 26943, 30563, 201341, 124983, 91819, 164543, 32309, 91636, 137647, 116126, 15191, 189995, 64968, 155474, 61629, 139000, 62705, 95864, 75253, 28133, 61030, 192741, 124648, 62812, 115955, 89735, 179243, 169419, 158503, 73019, 42969, 127175, 195093, 171307, 130625, 44335, 45946, 79643, 179432, 198517, 111278, 125890, 48933, 159081, 135927, 27087, 84670, 60338, 106871, 178972, 104559, 173980, 88024, 201716, 73571, 122134, 92943, 192011, 183985, 144819, 144207, 160677, 122243, 89212, 58318, 100214, 81683, 203126, 123726, 118973, 170159, 71567, 83915, 79447, 109767, 127788, 32588, 55738, 154600, 85970, 20318, 81431, 202549, 206804, 48427, 141007, 206757, 62166, 184790, 85489, 54983, 89509, 201198, 72062, 192978, 155213, 73117, 190698, 108238, 79515, 73307, 151679, 99647, 21343, 40627, 13817, 46491, 45519, 22719, 85628, 176595, 171535, 170980, 170887, 59865, 206550, 190825, 101775, 105926, 105115, 175345, 101975, 106186, 52126, 36207, 187415, 108655, 91640, 62109, 80091, 75731, 125102, 39165, 122784, 140759, 179905, 115055, 46391, 81266, 80491, 196168, 73054, 126616, 59881, 30393, 75223, 91199, 101182, 11133, 95465, 155523, 32105, 143162, 32216, 59163, 149370, 137724, 52350, 155556, 177904, 176303, 129555, 199343, 121229, 23979, 107838, 162364, 204009, 160923, 23469, 203221, 76647, 106029, 88444, 64810, 205243, 207527, 177721, 119403, 46515, 13245, 39835, 79255, 192133, 108789, 77737, 195908, 153308, 61081, 55181, 147064, 96933, 105630, 183070, 124138, 68989, 63372, 61209, 112158, 125467, 166870, 58605, 28278, 124307, 84918, 96399, 120026, 79793, 73532, 118185, 161505, 92751, 144798, 158123, 45787, 102647, 15222, 198431, 19407, 89645, 173909, 124047, 159429, 42399, 45942, 55266, 23993, 16270, 195969, 64555, 196240, 112403, 53943, 27603, 102316, 188256, 122465, 174821, 117973, 32027, 73397, 107443, 192937, 121927, 162612, 177363, 124092, 182637, 170823, 30138, 167401, 26349, 95954, 105051, 154781, 182739, 142322, 154593, 87782, 112853, 143267, 104051, 153404, 96541, 61814, 47917, 164733, 89302, 62424, 116311, 157491, 39613, 16218, 165838, 193476, 101874, 91634, 139149, 76471, 79067, 171697, 154206, 81368, 118055, 52843, 114561, 170233, 62253, 76651, 121297, 55737, 111923, 189749, 58431, 138876, 163154, 175414, 204563, 158842, 62555, 143305, 192134, 13818, 185166, 71612, 138895, 114096, 208083, 147346, 174964, 107435, 125560, 170894, 178586, 167737, 150778, 115295, 199623, 129221, 144888, 38687, 189386, 80943, 54494, 118172, 122308, 31861, 170891, 115166, 47451, 182875, 49027, 56651, 22971, 169875, 152411, 80189, 62669, 69533, 138993, 206173, 138958, 130244, 80355, 48302, 129704, 46053, 170744, 183992, 124836, 48250, 79546, 172510, 208051, 78777, 16281, 95156, 199143, 181236, 116615, 115549, 62188, 141259, 13179, 112281, 96041, 154227, 136158, 48283, 177366, 170443, 179484, 181614, 177261, 153494, 187848, 194914, 31629, 87290, 94893, 194590, 127814, 186825, 48579, 150268, 32142, 146525, 169559, 127203, 110245, 20315, 156887, 154059, 183025, 95571, 206013, 62622, 203722, 187437, 119598, 113091, 148476, 119529, 121066, 185964, 158779, 26604, 120517, 182188, 109909, 48948, 73676, 120292, 177617, 141223, 203166, 159807, 107002, 174962, 97592, 87271, 143847, 62930, 199637, 130241, 156573, 97157, 119102, 88562, 97323, 191139, 28311, 138135, 19583, 182462, 181884, 187498, 44462, 114504, 53998, 64613, 187174, 88036, 124189, 136574, 142254, 137015, 79159, 136683, 93138, 28487, 58291, 15069, 125864, 95580, 138725, 101353, 108504, 178889, 88727, 182776, 162243, 157365, 151222, 118385, 77103, 22390, 60814, 181143, 103835, 47574, 126499, 44459, 127460, 114307, 134525, 80756, 183420, 112971, 103087, 140790, 58974, 151449, 163028, 59815, 186730, 184258, 177012, 202598, 178394, 170482, 110655, 204600, 145781, 137791, 121419, 177094, 162693, 76989, 89332, 184009, 113742, 129688, 65320, 54621, 169340, 49915, 28284, 188575, 191788, 79732, 109150, 160604, 86773, 163206, 187527, 126520, 162410, 110001, 113258, 170295, 129634, 60362, 57057, 31985, 76926, 95819, 146265, 176626, 176601, 144987, 61899, 61940, 163236, 176755, 118155, 158937, 162005, 169278, 187939, 178032, 161973, 117212, 76029, 121704, 46806, 87737, 167290, 202612, 178485, 90004, 81564, 204234, 120172, 15247, 38255, 154205, 88414, 55982, 171055};


int main() {
    srand(time(NULL));
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	int IT = 20;
	                 
	for (int i = 0; i < n; i++)
		mask[i] = good[i];

	for (int it = 0; it < IT; it++) {
		vector<int> q;
		for (int i = 0; i < n; i++) {
			if ((mask[i] >> it) & 1) {
				q.pb(i);
				in[it][i] = true;
		   	}
		}
		if ((int)q.size() == 0) {
			ign[it] = true;
			continue;
		}
		cout << (int)q.size() << endl;
		for (auto x : q) 
			cout << x + 1 << " ";
		cout << endl;
		for (int i = 0; i < n;i++) 
			cin >> res[it][i];
	}

	cout << -1 << endl;
	for (int i = 0; i < n; i++) {
		int ans = Q;
		for (int j = 0; j < IT; j++) {
			if (ign[j]) continue;
			if (!in[j][i])
				ans = min(ans, res[j][i]);
		}
		cout << ans << " ";
	}
	cout << endl;
    return 0;
}   