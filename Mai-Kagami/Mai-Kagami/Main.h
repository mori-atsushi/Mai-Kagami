#ifndef __MAIN_H_INCLUDED__
#define __MAIN_H_INCLUDED__

#define SIZE_RATE	1
#define WIDTH		1080
#define HEIGHT		1920

#define NFC_POS		HEIGHT * 0.85
#define NFC_FLAG	TRUE	//NFCカードを読み込むかどうか(TRUE:読み込む/FALSE:読み込まない)
#define TOUCH_FLAG	TRUE	//サイドタッチパネルを使うか
#define KINECT_FLAG	FALSE	//KINECTを使用するかどうか(TRUE:使用する/FALSE:使用しない)
#define FULLSCREEN_FLAG	TRUE	//フルスクリーンにするか


typedef enum {
	TOP,
	SONG_SELECT,
	THROUGH,
	THROUGH_RESULT,
	PART,
	PART_RESULT,
	THROUGH_OPTION,
	PART_OPTION
} MainScene;

#endif