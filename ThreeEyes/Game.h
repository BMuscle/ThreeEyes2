#pragma once
#include"DxLib.h"
#include "MyWindow.h"
#include "MyMouse.h"
#define RECT_WIDTH 100	//１マスの幅
#define RECT_HEIGHT 100	//１マスの高さ
#define BOARD_SIZE 3 //盤面の１方向のマスの数

#define BOARD_WIDTH (RECT_WIDTH * BOARD_SIZE)	//盤面の幅
#define BOARD_HEIGHT (RECT_HEIGHT * BOARD_SIZE) //盤面の高さ

#define BOARD_OFFSET_X ((WINDOW_WIDTH / 2) - (RECT_WIDTH * BOARD_SIZE / 2)) //盤面の左上起点X
#define BOARD_OFFSET_Y ((WINDOW_HEIGHT / 2) - (RECT_HEIGHT * BOARD_SIZE /2))//盤面の左上起点Y

struct Board;	//盤面情報の構造体	
struct Pos;		//盤面の座標情報の構造体
enum TURN;		//ターン情報の列挙型

void Game_Initialize(void);	//ゲームの初期化処理
void Game_Finalize(void);	//ゲームの終了処理
void Game_Update(void);		//ゲームの計算処理
void Game_Draw(void);		//ゲームの描画処理



void boardDraw(void);//画像で盤面描画
void boardDrawString(void);//文字で盤面描画

BOOL getKey(Pos *pos);//ボード上の座標取得　要修正
BOOL getMousePos(Pos *pos);//ボード上マウス座標取得

BOOL isSetStone(Board board, int x, int y);//石が置けるか？
BOOL isWin(Board board, TURN turn);//勝っている？
BOOL isDrow(Board board);//引き分け？

Pos cpuThink(Board board, TURN turn);//CPUの手　計算

int getGameResult(void);//ゲームの勝ち負け引き分けの結果を受け取る
int isGameEnd(void);	//ゲームが終わっているか判定
TURN changeTurn(TURN turn);//ターンを交代する

void timeCnt(void);  //cpuの思考時間