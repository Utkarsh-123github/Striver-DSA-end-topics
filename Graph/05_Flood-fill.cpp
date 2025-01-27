// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

 

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

// Output: [[2,2,2],[2,2,0],[2,0,1]]

// Explanation:



// From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

// Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

// Example 2:

// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

// Output: [[0,0,0],[0,0,0]]

// Explanation:

// The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int,int>>q;
    int m = image.size();
    int n = image[0].size();
    if(image[sr][sc] == color)return image;
    int parentColor = image[sr][sc];
    image[sr][sc] = color;
    q.push({sr,sc});
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(auto [dr,dc] : directions){
            int nr = row + dr;
            int nc = col + dc;
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || image[nr][nc] != parentColor){
                continue;
            }
            image[nr][nc] = color;
            q.push({nr,nc});
        }
    }
    return image;
}