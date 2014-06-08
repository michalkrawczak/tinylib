#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <utility>

class Encrypt
{
public:
    Encrypt();
    static std::pair<std::pair<int,int>,std::pair<int,int>> getKeys();
    static int crypt(int,int,int);
private:
    static int gcd(int,int);
    static int reverseMod(int,int);
    static int powerMod(int,int,int);

    static constexpr int primes[1000] = {	 15469313, 15469327, 15469339, 15469343, 15469351, 15469373, 15469453, 15469459, 15469469, 15469511,
                            15469513, 15469537, 15469577, 15469579, 15469583, 15469613, 15469621, 15469633, 15469679, 15469687,
                             15469703, 15469709, 15469747, 15469759, 15469763, 15469771, 15469787, 15469793, 15469829, 15469871,
                            15469873, 15469897, 15469901, 15469939, 15469943, 15469967, 15469991, 15469999, 15470029, 15470057,
                             15470071, 15470083, 15470089, 15470093, 15470111, 15470113, 15470129, 15470131, 15470159, 15470197,
                             15470201, 15470249, 15470267, 15470269, 15470303, 15470327, 15470347, 15470353, 15470359, 15470363,
                             15470419, 15470443, 15470447, 15470461, 15470471, 15470509, 15470531, 15470537, 15470549, 15470563,
                             15470569, 15470573, 15470593, 15470597, 15470621, 15470639, 15470641, 15470681, 15470711, 15470729,
                             15470747, 15470779, 15470783, 15470813, 15470827, 15470831, 15470837, 15470843, 15470869, 15470879,
                             15470893, 15470911, 15470929, 15470933, 15470941, 15470947, 15470957, 15470989, 15470993, 15471031,
                             15471041, 15471059, 15471061, 15471067, 15471097, 15471103, 15471107, 15471121, 15471161, 15471163,
                             15471167, 15471199, 15471233, 15471257, 15471259, 15471289, 15471293, 15471307, 15471311, 15471331,
                            15471347, 15471349, 15471353, 15471359, 15471361, 15471367, 15471371, 15471383, 15471419, 15471457,
                             15471461, 15471497, 15471499, 15471551, 15471553, 15471557, 15471583, 15471593, 15471623, 15471641,
                             15471727, 15471737, 15471739, 15471767, 15471769, 15471773, 15471779, 15471793, 15471811, 15471889,
                             15471923, 15471943, 15471949, 15471961, 15471971, 15471991, 15472001, 15472019, 15472021, 15472033,
                             15472043, 15472081, 15472087, 15472097, 15472103, 15472117, 15472133, 15472147, 15472151, 15472153,
                            15472187, 15472189, 15472201, 15472207, 15472241, 15472271, 15472273, 15472297, 15472313, 15472321,
                             15472333, 15472349, 15472357, 15472361, 15472367, 15472411, 15472417, 15472421, 15472427, 15472433,
                             15472463, 15472481, 15472487, 15472489, 15472519, 15472559, 15472571, 15472579, 15472591, 15472603,
                             15472619, 15472637, 15472651, 15472657, 15472663, 15472673, 15472679, 15472687, 15472693, 15472753,
                            15472757, 15472759, 15472781, 15472789, 15472811, 15472829, 15472837, 15472871, 15472889, 15472901,
                             15472909, 15472931, 15472957, 15472981, 15472987, 15473021, 15473023, 15473027, 15473039, 15473041,
                             15473053, 15473057, 15473071, 15473083, 15473093, 15473119, 15473131, 15473197, 15473219, 15473231,
                            15473233, 15473261, 15473267, 15473279, 15473291, 15473303, 15473317, 15473323, 15473347, 15473351,
                             15473357, 15473369, 15473401, 15473407, 15473431, 15473459, 15473473, 15473477, 15473489, 15473533,
                             15473539, 15473551, 15473569, 15473597, 15473603, 15473609, 15473663, 15473671, 15473683, 15473699,
                            15473701, 15473741, 15473761, 15473767, 15473797, 15473813, 15473831, 15473839, 15473863, 15473879,
                             15473891, 15473903, 15473993, 15474047, 15474049, 15474059, 15474071, 15474073, 15474127, 15474133,
                             15474143, 15474149, 15474167, 15474169, 15474181, 15474187, 15474203, 15474211, 15474269, 15474293,
                             15474307, 15474317, 15474323, 15474337, 15474359, 15474373, 15474383, 15474409, 15474443, 15474451,
                             15474491, 15474497, 15474499, 15474509, 15474517, 15474523, 15474527, 15474551, 15474553, 15474577,
                             15474583, 15474593, 15474601, 15474623, 15474647, 15474649, 15474659, 15474689, 15474707, 15474713,
                             15474727, 15474733, 15474749, 15474751, 15474773, 15474779, 15474787, 15474793, 15474799, 15474803,
                             15474829, 15474841, 15474853, 15474857, 15474863, 15474871, 15474881, 15474931, 15474937, 15474959,
                            15474961, 15474971, 15474973, 15474997, 15475001, 15475003, 15475007, 15475013, 15475027, 15475039,
                             15475043, 15475069, 15475091, 15475111, 15475121, 15475123, 15475129, 15475147, 15475153, 15475171,
                             15475193, 15475199, 15475223, 15475247, 15475249, 15475259, 15475261, 15475277, 15475279, 15475307,
                             15475337, 15475387, 15475403, 15475429, 15475451, 15475469, 15475483, 15475501, 15475507, 15475511,
                             15475529, 15475567, 15475597, 15475631, 15475637, 15475667, 15475673, 15475679, 15475693, 15475697,
                            15475699, 15475703, 15475739, 15475751, 15475753, 15475771, 15475777, 15475783, 15475847, 15475871,
                             15475891, 15475909, 15475951, 15475969, 15475973, 15475981, 15475991, 15476003, 15476009, 15476017,
                             15476029, 15476039, 15476081, 15476117, 15476119, 15476189, 15476213, 15476243, 15476269, 15476281,
                             15476287, 15476291, 15476303, 15476333, 15476339, 15476353, 15476389, 15476413, 15476437, 15476449,
                             15476453, 15476473, 15476491, 15476501, 15476543, 15476551, 15476561, 15476569, 15476609, 15476611,
                             15476623, 15476663, 15476683, 15476711, 15476717, 15476729, 15476731, 15476759, 15476777, 15476831,
                             15476837, 15476873, 15476893, 15476899, 15476941, 15476957, 15476977, 15476983, 15477031, 15477037,
                            15477041, 15477043, 15477071, 15477073, 15477079, 15477083, 15477149, 15477151, 15477167, 15477193,
                             15477197, 15477221, 15477239, 15477247, 15477251, 15477269, 15477281, 15477299, 15477307, 15477313,
                             15477317, 15477331, 15477337, 15477353, 15477373, 15477383, 15477389, 15477391, 15477403, 15477409,
                             15477421, 15477467, 15477481, 15477487, 15477493, 15477509, 15477547, 15477557, 15477559, 15477569,
                             15477577, 15477589, 15477607, 15477613, 15477629, 15477659, 15477661, 15477697, 15477703, 15477719,
                            15477731, 15477733, 15477739, 15477751, 15477767, 15477797, 15477809, 15477811, 15477821, 15477841,
                            15477857, 15477859, 15477863, 15477887, 15477907, 15477911, 15477941, 15478003, 15478009, 15478013,
                             15478031, 15478063, 15478081, 15478121, 15478129, 15478147, 15478153, 15478171, 15478187, 15478219,
                             15478261, 15478271, 15478283, 15478297, 15478301, 15478319, 15478349, 15478363, 15478433, 15478439,
                             15478447, 15478453, 15478457, 15478493, 15478501, 15478511, 15478523, 15478571, 15478583, 15478601,
                             15478621, 15478649, 15478657, 15478681, 15478693, 15478733, 15478741, 15478777, 15478807, 15478843,
                             15478849, 15478867, 15478873, 15478877, 15478909, 15478921, 15478927, 15478949, 15478961, 15478963,
                             15478973, 15478999, 15479029, 15479033, 15479039, 15479059, 15479071, 15479081, 15479083, 15479089,
                             15479111, 15479131, 15479143, 15479153, 15479173, 15479203, 15479221, 15479227, 15479237, 15479257,
                             15479273, 15479287, 15479291, 15479293, 15479329, 15479341, 15479363, 15479371, 15479377, 15479389,
                             15479393, 15479411, 15479413, 15479419, 15479459, 15479467, 15479473, 15479489, 15479507, 15479539,
                             15479549, 15479567, 15479573, 15479599, 15479603, 15479609, 15479617, 15479627, 15479641, 15479647,
                             15479677, 15479683, 15479687, 15479701, 15479753, 15479831, 15479839, 15479857, 15479879, 15479887,
                             15479899, 15479921, 15479929, 15479953, 15479969, 15479987, 15479993, 15480029, 15480053, 15480103,
                             15480107, 15480121, 15480137, 15480151, 15480163, 15480181, 15480197, 15480203, 15480211, 15480233,
                             15480239, 15480263, 15480271, 15480281, 15480299, 15480313, 15480331, 15480341, 15480347, 15480349,
                             15480373, 15480379, 15480407, 15480431, 15480433, 15480463, 15480499, 15480511, 15480527, 15480529,
                             15480533, 15480581, 15480601, 15480617, 15480631, 15480637, 15480643, 15480677, 15480691, 15480697,
                             15480709, 15480713, 15480721, 15480737, 15480757, 15480767, 15480779, 15480853, 15480869, 15480901,
                             15480923, 15480937, 15480947, 15480961, 15480967, 15480979, 15481009, 15481021, 15481043, 15481057,
                             15481061, 15481073, 15481153, 15481163, 15481171, 15481177, 15481199, 15481211, 15481217, 15481223,
                            15481259, 15481261, 15481289, 15481303, 15481321, 15481327, 15481363, 15481391, 15481399, 15481421,
                             15481439, 15481463, 15481469, 15481481, 15481483, 15481513, 15481537, 15481549, 15481567, 15481573,
                             15481589, 15481601, 15481607, 15481619, 15481633, 15481657, 15481663, 15481727, 15481733, 15481769,
                             15481787, 15481793, 15481801, 15481819, 15481859, 15481871, 15481897, 15481901, 15481933, 15481981,
                             15481993, 15481997, 15482011, 15482023, 15482029, 15482119, 15482123, 15482149, 15482153, 15482161,
                             15482167, 15482177, 15482219, 15482231, 15482263, 15482309, 15482323, 15482329, 15482333, 15482347,
                             15482371, 15482377, 15482387, 15482419, 15482431, 15482437, 15482447, 15482449, 15482459, 15482477,
                            15482479, 15482531, 15482567, 15482569, 15482573, 15482581, 15482627, 15482633, 15482639, 15482669,
                            15482681, 15482683, 15482711, 15482729, 15482743, 15482771, 15482773, 15482783, 15482807, 15482809,
                             15482827, 15482851, 15482861, 15482893, 15482911, 15482917, 15482923, 15482941, 15482947, 15482977,
                             15482993, 15483023, 15483029, 15483067, 15483077, 15483079, 15483089, 15483101, 15483103, 15483121,
                             15483151, 15483161, 15483211, 15483253, 15483317, 15483331, 15483337, 15483343, 15483359, 15483383,
                             15483409, 15483449, 15483491, 15483493, 15483511, 15483521, 15483553, 15483557, 15483571, 15483581,
                             15483619, 15483631, 15483641, 15483653, 15483659, 15483683, 15483697, 15483701, 15483703, 15483707,
                             15483731, 15483737, 15483749, 15483799, 15483817, 15483829, 15483833, 15483857, 15483869, 15483907,
                             15483971, 15483977, 15483983, 15483989, 15483997, 15484033, 15484039, 15484061, 15484087, 15484099,
                             15484123, 15484141, 15484153, 15484187, 15484199, 15484201, 15484211, 15484219, 15484223, 15484243,
                             15484247, 15484279, 15484333, 15484363, 15484387, 15484393, 15484409, 15484421, 15484453, 15484457,
                            15484459, 15484471, 15484489, 15484517, 15484519, 15484549, 15484559, 15484591, 15484627, 15484631,
                             15484643, 15484661, 15484697, 15484709, 15484723, 15484769, 15484771, 15484783, 15484817, 15484823,
                             15484873, 15484877, 15484879, 15484901, 15484919, 15484939, 15484951, 15484961, 15484999, 15485039,
                             15485053, 15485059, 15485077, 15485083, 15485143, 15485161, 15485179, 15485191, 15485221, 15485243,
                             15485251, 15485257, 15485273, 15485287, 15485291, 15485293, 15485299, 15485311, 15485321, 15485339,
                            15485341, 15485357, 15485363, 15485383, 15485389, 15485401, 15485411, 15485429, 15485441, 15485447,
                            15485471, 15485473, 15485497, 15485537, 15485539, 15485543, 15485549, 15485557, 15485567, 15485581,
                            15485609, 15485611, 15485621, 15485651, 15485653, 15485669, 15485677, 15485689, 15485711, 15485737,
                             15485747, 15485761, 15485773, 15485783, 15485801, 15485807, 15485837, 15485843, 15485849, 15485857};

};

#endif // ENCRYPT_H
