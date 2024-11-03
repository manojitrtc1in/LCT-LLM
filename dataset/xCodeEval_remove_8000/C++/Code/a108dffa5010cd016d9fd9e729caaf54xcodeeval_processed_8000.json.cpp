





















using namespace std;
long long id2, id8, id15, id9, id6, id3, id7;

vector < vector < int > > id10(1000005);
bool NTxCCftnlWIrxtPnPEKxQKWpHpKNNElwDNWKbxgfZawsSFtpwpJpwAZkjsaHkAmdFLdRHqKqlQGBaXpHZKoiGuRvsABDSOSrpsSnmgjmXwhPtQ[1000005];
long long vgNuOIxyeGKORjwkaXYTSwHgdkkTFWdoARFQqMuSJSawkkVcsLBdYegQSRfOindbAJPgRZnRoLcIBRtQpKVWsItJinKWBnAOMjzCixoSaUUYhl[1000005];
long long gezlVQeLmHpVbHOpqExOrdYvmLWPjjncHyUtCmcEGZIhxRgqxbjUxXjTmuDiOZZRSPJYtNeecWpJXByKbqwztvFxNxAhJNFZznamIOgpYYJxzL[1000005];
long long ONqJWTpbgCuWcxguPXkHvjVgQYPCMHgoqCYsQRIIeNsCiEflMpepVxWxIbIKPyLmOsluqMlvZzrvFZQekAbNPVPaVFqnrRFXfijHAmcUwvRYBR[1000005];
struct lol
{
        int id0;
        int yVZEUVAonmLTYdCTzXeARZnxdSuGJFyPKStNjylcRbywtVYreSzzdoZjzHCCZTrUYJyPlFxSGLAVgutXnyHlYxfBBfkreVfgaJpfDpdmQWLvmW;
};

vector < vector < lol > > id13(1000005);
void id14(int id0,int id4)
{
        NTxCCftnlWIrxtPnPEKxQKWpHpKNNElwDNWKbxgfZawsSFtpwpJpwAZkjsaHkAmdFLdRHqKqlQGBaXpHZKoiGuRvsABDSOSrpsSnmgjmXwhPtQ[id0] = 1;
        for (int id16 = 0; id16 < id10[id0].size(); id16++)
        {
                int id12 = id10[id0][id16];
                if (NTxCCftnlWIrxtPnPEKxQKWpHpKNNElwDNWKbxgfZawsSFtpwpJpwAZkjsaHkAmdFLdRHqKqlQGBaXpHZKoiGuRvsABDSOSrpsSnmgjmXwhPtQ[id12] == 0)
                {
                        id13[id0].push_back({ id12,id4 });
                        id13[id12].push_back({ id0,id4 });
                        if (id4 == 2)id14(id12, 3);
                        else id14(id12, 2);
                }

        }
}
long long TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[1000005];
void id11()
{
        cin >> id2;
        bool id17 = 0;
        for (int id16 = 1; id16 < id2; id16++)
        {
                cin >> id8 >> id15;
                gezlVQeLmHpVbHOpqExOrdYvmLWPjjncHyUtCmcEGZIhxRgqxbjUxXjTmuDiOZZRSPJYtNeecWpJXByKbqwztvFxNxAhJNFZznamIOgpYYJxzL[id16] = id8;
                ONqJWTpbgCuWcxguPXkHvjVgQYPCMHgoqCYsQRIIeNsCiEflMpepVxWxIbIKPyLmOsluqMlvZzrvFZQekAbNPVPaVFqnrRFXfijHAmcUwvRYBR[id16] = id15;
                id10[id8].push_back(id15);
                id10[id15].push_back(id8);
                TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[id8]++;
                TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[id15]++;
                if (TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[id8] > 2 || TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[id15] > 2) id17 = 1;
        }
        if (id17 == 1) { cout << -1<<'\n';
        for (int id16 = 1; id16 <= id2; id16++)
        {
                TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[id16] = 0;
                NTxCCftnlWIrxtPnPEKxQKWpHpKNNElwDNWKbxgfZawsSFtpwpJpwAZkjsaHkAmdFLdRHqKqlQGBaXpHZKoiGuRvsABDSOSrpsSnmgjmXwhPtQ[id16] = 0;
                id10[id16].clear();
                id13[id16].clear();
        }
        return; }
        

        for (int id16 = 1; id16 <= id2; id16++)
        {
                if (TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[id16] == 1) { id14(id16, 2); break; }
        }

        for (int id16 = 1; id16 < id2; id16++)
        {
                id8 = gezlVQeLmHpVbHOpqExOrdYvmLWPjjncHyUtCmcEGZIhxRgqxbjUxXjTmuDiOZZRSPJYtNeecWpJXByKbqwztvFxNxAhJNFZznamIOgpYYJxzL[id16];
                id15 = ONqJWTpbgCuWcxguPXkHvjVgQYPCMHgoqCYsQRIIeNsCiEflMpepVxWxIbIKPyLmOsluqMlvZzrvFZQekAbNPVPaVFqnrRFXfijHAmcUwvRYBR[id16];
                for (int id5 = 0; id5 < id13[id8].size(); id5++)
                {
                        if (id13[id8][id5].id0 == id15) { cout << id13[id8][id5].yVZEUVAonmLTYdCTzXeARZnxdSuGJFyPKStNjylcRbywtVYreSzzdoZjzHCCZTrUYJyPlFxSGLAVgutXnyHlYxfBBfkreVfgaJpfDpdmQWLvmW << " "; break; }

                }

        }
        cout << '\n';
        for (int id16 = 1; id16 <= id2; id16++)
        {
                TYyzIroQxiadUcWocOJsftLNRPUnFdPnbTrbmJsLAEakMAKQzPftnPIDMUrAVqpPcMFvweccDEIRiNsbKZIlelXIvAJhzZEqzRQGKpDtsHhYdt[id16] = 0;
                NTxCCftnlWIrxtPnPEKxQKWpHpKNNElwDNWKbxgfZawsSFtpwpJpwAZkjsaHkAmdFLdRHqKqlQGBaXpHZKoiGuRvsABDSOSrpsSnmgjmXwhPtQ[id16] = 0;
                id10[id16].clear();
                id13[id16].clear();
        }
}

 int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int id1;
        id1 = 1;
        cin >> id1;
        while (id1 != 0)
        {
                id11();
                id1--;
        }
return 0;
}