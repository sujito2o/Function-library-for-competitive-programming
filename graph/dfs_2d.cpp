const int dr[]={0,0,1,-1};
const int dc[]={1,-1,0,0};

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dr[6]={-1,-1,0,1,1,0};int dc[6]={0,1,1,0,-1,-1};//hexagonal

int cols, rows, maxd, maxr, maxc;
char s[1005][1005], v[1005][1005];

void dfs(int r, int c){
	
	v[r][c]=1;
	For(i,0,3) if (r+dr[i]>=0&&r+dr[i]<rows&&c+dc[i]>=0&&c+dc[i]<cols&&
			v[r+dr[i]][c+dc[i]]==0&&s[r+dr[i]][c+dc[i]]=='.')
		dfs(r+dr[i],c+dc[i]);
}
