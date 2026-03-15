#include<iostream>
using namespace std;

void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor)
{
    int m = image.size();
    int n = image[0].size();

    if(r < 0 || c < 0 || r >= m || c >= n || image[r][c] != originalColor) return;

    image[r][c] = newColor;

    dfs(image, r + 1, c, originalColor, newColor);
    dfs(image, r - 1, c, originalColor, newColor);
    dfs(image, r, c + 1, originalColor, newColor);
    dfs(image, r, c - 1, originalColor, newColor);
}

vector<vector<int>> op_way(vector<vector<int>>& images, int sr, int sc, int newColor)
{
    int originalColor = images[sr][sc];

    if(originalColor == newColor) return images;

    dfs(images, sr, sc, originalColor, newColor);
    return images;
}

vector<vector<int>> other_way(vector<vector<int>>& images, int sr, int sc, int newColor)
{
    int m = images.size();
    int n = images.size();

    images[sr][sc] = newColor;
    queue<pair<int, int>> q;
    int cnt = 0;

    q.push({sr, sc});
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!q.empty())
    {
        int k = q.size();

        while(k--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || images[nx][ny] != 1) continue;

                images[nx][ny] = newColor;
                q.push({nx, ny}); 
            }
        }
    }
    return images;
}

int main()
{
    int sr = 1, sc = 1;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int newColor = 2;

    // vector<vector<int>> ans = op_way(image, sr, sc, newColor);
    vector<vector<int>> ans = other_way(image, sr, sc, newColor);
    for(auto i: ans)
    {
        for(auto ii: i)
        {
            cout<<ii<<" ";
        }
        cout<<endl;
    }
}