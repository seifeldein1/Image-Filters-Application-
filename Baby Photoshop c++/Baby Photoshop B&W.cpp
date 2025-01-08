// FCAI – Programming 1 – 2022 - Assignment 3
// Program Name: first CS112-203-2nd - S5,S6-20210536-20211048-20210529-A3-FULL.cpp
// Program Description:  ALL filters of the project
// Last Modification Date: 18/4/2022
// Author and ID and Group:
// 1- saif eldeen mohamed fathy /  ID: 20210536 / g(a) /s5,s6
// 2- noureen saad mamdouh / ID: 20210529  / g(a)/s5,s6
// 3- Salma Abdelaziz Nabieh Soliman / ID: 20211048  / g(a)/s5,s6
// Teaching Assistant:  eng.Hager
// Purpose: implementation  some filters on  an image
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void bw_filter();
void invert_filter();
void merge_filter();
void flib_filter();
void l_filter();
void d_filter();
void rotate_filter();
void detect_edges();
void zoom_filter(int strat1,int start2,int end1,int end2);
void shrink2_filter();
void shrink3_filter();
void shrink4_filter();
void mleft_filter();
void mright_filter();
void mup_filter();
void downm_filter();
void shuffle_filter();
void blur_filter();
int main(){
    string rest;
    cout<<"ahlan ya user ya habibi "<<char(3)<<" :)"<<endl;
    //loading the image
    loadImage();

    do{//starting page
    int op;
    cout<<"   --- menu ---"<<endl;
    cout<<"1-Black & White Filter"<<endl;
    cout<<"2-Invert Filter"<<endl;
    cout<<"3-Merge Filter"<<endl;
    cout<<"4-Flip Image"<<endl;
    cout<<"5-Darken and Lighten Image"<<endl;
    cout<<"6-Rotate Image"<<endl;
    cout<<"7-Detect Image Edges"<<endl;
    cout<<"8-Enlarge Image"<<endl;
    cout<<"9-Shrink Image"<<endl;
    cout<<"10-Mirror 1/2 Image"<<endl;
    cout<<"11- Shuffle Image"<<endl;
    cout<<"12- Blur Image"<<endl;
    cout<<"13- Save the image to a file"<<endl;
    cout<<"14-exit"<<endl;
    cout<<"Please enter a choice from 1 to 14 >>> ";
    cin>>op;
    while (op <=0 ||op > 14) {
            cout << "your input is not valid , please enter a choice in range [1,14] only" << endl;
                    cin >> op;
                }

    char ch;
    if (op == 10){
        ch = 'a';
    }
    else if (op == 11){
        ch = 'b';
    }
    else if (op == 12){
        ch = 'c';
    }
    else if (op == 13){
        ch = 's';
    }
    else if (op == 14){
        ch = 'e';
    }
    else {
    stringstream ss;
    ss << op;
    string strop = ss.str();
    int n = strop.length();
    char choice[2];
    strcpy(choice, strop.c_str());
    for (int i = 0; i < n; i++){
        ch = choice[i];}
    }
    //////////////////switch between the filters////////////////////////////////////////////
    switch (ch){
        case '1':// 1-bw filter
        bw_filter();
        saveImage ();
    break;
    case '2':// 2-Invert Filter
        invert_filter();
        saveImage ();
    break;
    case '3':// 3- Merge Filter
        merge_filter();
        saveImage ();
    break;
    case '4':{// 4- Flip Image
        int fch = 0;
        cout << "choose a Flip 1- horizontally or 2-vertically ?"<<endl;
        cout<<"Please enter your choice >>> ";
        cin>>fch;
        while (fch <=0 ||fch > 2) {
            cout << "your input is not valid , please enter 1 or 2 only" << endl;
                    cin >> fch;
                }
        if ( fch == 1 ){
            flib_filter();
            saveImage ();
            break;
        }
        else if ( fch == 2 ){
            flib_filter();
            rotate_filter();
            rotate_filter();
            saveImage ();
            break;
        }break;}
    case '5'://5- Darken and Lighten Image
        {
        int dch = 0;
        cout << "choose a change 1- darken  or 2-lighten ?"<<endl;
        cout<<"Please enter your choice >>> ";
        cin>>dch;
        while (dch <=0 ||dch > 2) {
            cout << "your input is not valid , please enter 1 or 2 only" << endl;
                    cin >> dch;
                }
        if (dch == 1 ){
            d_filter();
            saveImage();
            }
        else if (dch == 2){
            l_filter();
            saveImage();
            }
        }
    break;
    case '6':// 6- Rotate Image
        {
        int rch = 0;
        cout << " Rotate (90), (180) or (270) degrees?"<<endl;
        cout<<"Please enter the degrees >>> ";
        cin>>rch;
        while (rch != 90 && rch != 180 && rch != 270 ) {
            cout << "your input is not valid , please enter (90), (180) or (270) only" << endl;
            cin >> rch;
                }
        if ( rch == 90 ){
            rotate_filter();
            saveImage ();
            break;
        }
        else if ( rch == 180 ){
            rotate_filter();
            rotate_filter();
            saveImage ();
            break;
        }
        else if ( rch == 270 ){
            rotate_filter();
            rotate_filter();
            rotate_filter();
            saveImage ();
            break;
        }

    }
    case '7':// 7- Detect Image Edges
        detect_edges();
        invert_filter();
        saveImage ();
    break;
    case '8':{// 8- Enlarge Image
        cout <<"Which quarter to enlarge 1, 2, 3 or 4 ?"<<endl;
        int zch = 0;
        cout<<"Please enter your choice >>> ";
        cin>>zch;
        while (zch <=0 ||zch > 4) {
            cout << "your input is not valid , please enter 1, 2, 3 or 4 only" << endl;
                    cin >> zch;}
        if (zch == 1){
            zoom_filter(0,0,128,128);
            saveImage ();
        }
        else if (zch == 2){
            zoom_filter(0,128,128,256);
            saveImage ();
        }
        else if (zch == 3){
            zoom_filter(128,0,256,128);
            saveImage ();
        }
        else if (zch == 4){
            zoom_filter(128,128,256,256);
            saveImage ();
        }
    break;}
    case '9':{// 9- Shrink Image
        char sch;
        cout << " Shrink to  a-(1/2)  */*  b-(1/3)  */*  c-(1/4)"<<endl;
        cout<<"Please enter your choice >>> ";
        cin>>sch;
        while (sch != 'a' && sch != 'b' && sch != 'c' ) {
            cout << "your input is not valid , please enter a or b or c only" << endl;
            cin >> sch;
                }
        if ( sch == 'a' ){
            shrink2_filter();
            saveImage ();
            break;
        }
        else if ( sch == 'b' ){
            shrink3_filter();
            saveImage ();
            break;
        }
        else if ( sch == 'c' ){
            shrink4_filter();
            saveImage ();
            break;
        }
    break;}
    case 'a':{// a- Mirror 1/2 Image
        cout <<"Mirror 1-left, 2-right, 3-upper, 4-down side?"<<endl;
        int mch = 0;
        cout<<"Please enter your choice >>> ";
        cin>>mch;
        while (mch <=0 ||mch > 4) {
            cout << "your input is not valid , please enter 1, 2, 3 or 4 only" << endl;
                    cin >> mch;}
        if (mch == 1){
            mleft_filter();
            saveImage ();
        }
        else if (mch == 2){
            mright_filter();
            saveImage ();
        }
        else if (mch == 3){
            mup_filter();
            saveImage ();
        }
        else if (mch == 4){
            downm_filter();
            saveImage ();
        }
    break;}
    case 'b':{// b- Shuffle Image
        shuffle_filter();
        saveImage ();

    break;}
    case 'c':{// c- Blur Image
        blur_filter();
        saveImage ();

    break;}
    case 's':{// s- Save the image to a file
        saveImage ();
    break;}
    case 'e':{
        //exit
    cout << "thanks for using our app"<<endl;
    break;}

    }// end of switch

    cout << "Would you like to use any filter on the image again? (y/n)" << endl;
        cin >> rest;
        while (rest != "y"  && rest != "n" ) {
            cout << "your input is not valid , please enter y or n only <<<" << endl;
            cin >> rest;
        }

    }while (rest == "y" );
    cout << "Thank you for using our app"  << endl;


    return 0;
}//int main

//////////////////////////////////////////////////////////////////////////////////////////////////
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Please, enter file name of the image to process:";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
   cout << "your image ("<<imageFileName<<")is ready :) .... "<<endl;
}
///////////////////1-BW/////////////////////////////////////////////////////////////////////////////////
void bw_filter() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;
    }
  }
}
//////////////////2-negative filter/////////////////////////////////////////////////////////////////////
void invert_filter() {
    int av,n = 0;
     for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            n+= image[i][j];

    }
    av = (n/(265*265));
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        int x,res,n = 0;
        if (image[i][j] > av-40){
            n = image[i][j];
            res = 255 - n;
            image[i][j] = res;
            }
        else{
            x = image[i][j] +255;
            if (x >= 256){
                image[i][j] = 255;
            }
            else {
            n = image[i][j];
            res = 255 + n;
            image[i][j] = res;
            }
            }

    }
  }
}
/////////////////////3 - merge filter/////////////////////////////////////////
void merge_filter() {
    char mimage[256][256];
    unsigned char image2[256][256];
    char imageFileName2[100];

   // Get gray scale image 2 file name
   cout << "Please, enter file name of the second image to merge:";
   cin >> imageFileName2;

   // Add to it .bmp extension and load image
   strcat (imageFileName2, ".bmp");
   readGSBMP(imageFileName2, image2);
    for (int i = 0 ;i < SIZE; i++) {
        for (int j = 0 ;j < SIZE; j++) {
        mimage[i][j] = ((image[i][j])+(image2[i][j]))/2;

    }
  }
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = mimage[i][j];

    }
  }

}
////////////////4- flip filter/////////////////////////////////////////////
void flib_filter() {
    int nimage[256][256];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        nimage[255-j][i] = image[j][i];

    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = nimage[i][j];

    }
  }

}
/////////////////////5 a-Darken filter/////////////////////////////////////////
void d_filter() {
    int n,res = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            n = image[i][j];
            res = n ;
            res = res*0.5;
            image[i][j] = res;
    }
  }
}

/////////////////////5 b- Lighten filter/////////////////////////////////////////
void l_filter() {
    int x,n,res = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            x = image[i][j]*1.5;
            if (x > 255){
            image[i][j] = 255;
            }
            else{
            n = image[i][j];
            res = n;
            res = res *1.5;
            image[i][j] = res;}


    }
  }

}
////////////////6 -rotate filter//////////////////
void rotate_filter() {
    int nimage[256][256];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        nimage[i][j] = image[255-j][i];

    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = nimage[i][j];

    }
  }

}
/////////////////////7- detect edges/////////////////////////////////////////
void detect_edges() {
    int gx_m[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
    int gy_m[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
    int gx ,gy , pixel_v=0;
    int gimage[256][256];
    int dy[256][256];
    for (int i = 0 ;i<SIZE; i++) {
        for (int j = 0 ;j<SIZE; j++) {
            gx=0;
            gy=0;
            for (int x = 0 ;x<3; x++){
                for (int y = 0 ;y<3; y++){
                 gx += (image[(i-1)+x][(j-1)+y])*(gx_m[x][y]);
                 gy += (image[(i-1)+x][(j-1)+y])*(gy_m[x][y]);
                }
            }
         pixel_v = sqrt((pow(gx,2))+(pow(gy,2)));
         if( pixel_v > 255 ){
           gimage[i][j] = 255;
         }
         else{
            gimage[i][j] = pixel_v;
         }
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         if( gimage[i][j] != 255 ){
            gimage[i][j] = 0;
         }

    }
  }


  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = gimage[i][j];

    }
  }
}
/////////////////////8- zoom filter/////////////////////////////////////////
void zoom_filter(int s ,int start2,int end1,int end2) {
    int zimage[256][256];
    int zi ,zj;
    for (int i = s ,zi=0;i < end1&&zi<SIZE; i++,zi+=2) {
        for (int j = start2 ,zj=0;j < end2&&zj<SIZE; j++,zj+=2) {

        zimage[zi][zj] = image[i][j];
        zimage[zi][zj+1] = image[i][j];
        zimage[zi+1][zj] = image[i][j];
        zimage[zi+1][zj+1] = image[i][j];
    }
  }
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = zimage[i][j];

    }
  }

}
/////////////////////9- shrink  1/2 filter/////////////////////////////////////////
void shrink2_filter() {
    int simage[128][128];
    int si ,sj;
    for (int i = 0 ,si=0;i < 128&&si<SIZE; i++,si+=2) {
        for (int j = 0 ,sj=0;j < 128&&sj<SIZE; j++,sj+=2) {

        simage[i][j] = ((image[si][sj])+(image[si+1][sj+1]))/2;
        simage[i+1][j] = ((image[si+1][sj])+(image[si+1][sj+1]))/2;
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = 255;

    }
  }

    for (int i = 0; i < 128; i++) {
    for (int j = 0; j< 128; j++) {
        image[i][j] = simage[i][j];

    }
  }

}
/////////////////////9- shrink  1/3 filter/////////////////////////////////////////
void shrink3_filter() {
    int simage[85][85];
    int si ,sj;
    for (int i = 0 ,si=0;i < 85&&si<SIZE; i++,si+=3) {
        for (int j = 0 ,sj=0;j < 85&&sj<SIZE; j++,sj+=3) {

        simage[i][j] = ((image[si][sj])+(image[si+1][sj+1])+(image[si+2][sj+2]))/3;
        simage[i+1][j] = ((image[si+1][sj])+(image[si+1][sj+1])+(image[si+2][sj+2]))/3;
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = 255;

    }
  }

    for (int i = 0; i < 85; i++) {
    for (int j = 0; j< 85; j++) {
        image[i][j] = simage[i][j];

    }
  }

}
/////////////////////9- shrink  1/4 filter/////////////////////////////////////////
void shrink4_filter() {
    int simage[64][64];
    int si ,sj;
    for (int i = 0 ,si=0;i < 64&&si<SIZE; i++,si+=4) {
        for (int j = 0 ,sj=0;j < 64&&sj<SIZE; j++,sj+=4) {

        simage[i][j] = ((image[si][sj])+(image[si+1][sj+1])+(image[si+2][sj+2])+(image[si+3][sj+3]))/4;
        simage[i+1][j] = ((image[si+1][sj])+(image[si+1][sj+1])+(image[si+2][sj+2])+(image[si+3][sj+3]))/4;
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = 255;

    }
  }

    for (int i = 0; i < 64; i++) {
    for (int j = 0; j< 64; j++) {
        image[i][j] = simage[i][j];

    }
  }

}
////////////////a- 1/2 mirorr filter left //////////////////
void mleft_filter() {
    int mi,mj;
    int nimage[256][256];
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< 128; j++) {
        nimage[i][j] = image[i][j];

    }
  }
  for (int i = 0, mi =0; i < SIZE&& mi < SIZE; i++,mi++) {
    for (int j = 128 , mj = 128; j>=0&&mj<SIZE; j--,mj++) {
        nimage[mi][mj] = image[i][j];

    }
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = nimage[i][j];

    }
  }

}
////////////////a- 1/2 mirror filter  right //////////////////
void mright_filter() {
    int mi,mj;
    int nimage[256][256];
    for (int i = 0; i < SIZE; i++) {
    for (int j = 128; j <SIZE; j++) {
        nimage[i][j] = image[i][j];

    }
  }
  for (int i = 0, mi =0; i < SIZE&& mi < SIZE; i++,mi++) {
    for (int j = 128 , mj = 128; j<SIZE&&mj>= 0; j++,mj--) {
        nimage[mi][mj] = image[i][j];

    }
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = nimage[i][j];

    }
  }

}
////////////////a- 1/2 mirror filter  down //////////////////
void downm_filter() {
    int mi,mj;
    int nimage[256][256];
    for (int i = 128; i <SIZE ; i++) {
        for (int j = 0; j < SIZE; j++) {
        nimage[i][j] = image[i][j];

    }
  }
  for (int i = 128, mi =128; i < SIZE&& mi >=0 ; i++,mi--) {
    for (int j = 0 , mj = 0; j<SIZE&&mj < SIZE; j++,mj++) {
        nimage[mi][mj] = image[i][j];

    }
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = nimage[i][j];

    }
  }

}

////////////////a- 1/2 mirror filter  up //////////////////
void mup_filter() {
    int mi,mj;
    int nimage[256][256];
    for (int i = 0; i < 128; i++) {
    for (int j = 0; j <SIZE; j++) {
        nimage[i][j] = image[i][j];

    }
  }
  for (int i = 128, mi =128; i >= 0&& mi >=0 ; i--,mi++) {
    for (int j = 0 , mj = 0; j<SIZE&&mj < SIZE; j++,mj++) {
        nimage[mi][mj] = image[i][j];

    }
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = nimage[i][j];

    }
  }

}

/////////////////////b - Shuffle Image/////////////////////////////////////////
void shuffle_filter() {
    int simage1[128][128];
    int simage2[128][128];
    int simage3[128][128];
    int simage4[128][128];
    int sch[4];

  for (int i = 0,x=0 ;i<128&& x < 128; i++, x++) {
        for (int j = 0,y = 0 ;j<128&& y < 128; j++,y++) {

        simage1[x][y] = image[i][j];
    }
  }
  for (int i = 0 ,x =0 ;i<128 && x<128; i++,x++) {
        for (int j = 128,y=0;j<SIZE && y<128 ; j++,y++) {

        simage2[x][y] = image[i][j];
    }
  }
  for (int i = 128,x =0 ;i<SIZE&&x< 128; i++,x++) {
        for (int j = 0,y =0 ;j<128 && y< 128; j++,y++) {

        simage3[x][y] = image[i][j];
    }
  }
  for (int i = 128,x =0 ;i<SIZE && x<128; i++,x++) {
        for (int j = 128 ,y=0;j<SIZE&&y< 128; j++,y++) {

        simage4[x][y] = image[i][j];
    }
  }
  int sch1;
  cout<<"New order of quarters ? ..."<<endl;
  cout<<"please enter the order by one digit in once >>>";
  for (int i = 0 ;i < 4; i++){
    cin >> sch1;
    while (sch1 < 1 ||  sch1 > 4) {
                    cout << "your input is not valid , please enter 1 or 2 or 3 or 4 only " << endl;
                    cin >> sch1;
                }
    sch[i] =sch1;
  }

  //first quarter///////////////////////////
  for (int i = 0 , x= 0;i<128&&x<128; i++,x++) {
        for (int j = 0, y = 0 ;j<128 && y < 128 ; j++,y++) {
        if ( sch[0] == 1 ){
        image[i][j] = simage1[x][y];
    }//if
    else if ( sch[0] == 2 ){
        image[i][j] = simage2[x][y];
    }//else if
    else if ( sch[0] == 3 ){
        image[i][j] = simage3[x][y];
    }//else if
    else if ( sch[0] == 4 ){
        image[i][j] = simage4[x][y];
    }//else if


        }
  }
  //second quarter///////////////////////////
  for (int i = 0 , x= 0;i<128&&x<128; i++,x++) {
        for (int j = 128, y = 0 ;j<SIZE && y < 128 ; j++,y++) {
        if ( sch[1] == 1 ){
        image[i][j] = simage1[x][y];
    }//if
    else if ( sch[1] == 2 ){
        image[i][j] = simage2[x][y];
    }//else if
    else if ( sch[1] == 3 ){
        image[i][j] = simage3[x][y];
    }//else if
    else if ( sch[1] == 4 ){
        image[i][j] = simage4[x][y];
    }//else if


        }
  }
  //third quarter///////////////////////////
  for (int i = 128 , x= 0;i< SIZE &&x<128; i++,x++) {
        for (int j = 0, y = 0 ;j<128 && y < 128 ; j++,y++) {
        if ( sch[2] == 1 ){
        image[i][j] = simage1[x][y];
    }//if
    else if ( sch[2] == 2 ){
        image[i][j] = simage2[x][y];
    }//else if
    else if ( sch[2] == 3 ){
        image[i][j] = simage3[x][y];
    }//else if
    else if ( sch[2] == 4 ){
        image[i][j] = simage4[x][y];
    }//else if


        }
  }
  //FOURTH quarter///////////////////////////
  for (int i = 128 ,x= 0;i< SIZE &&x<128; i++,x++) {
        for (int j = 128, y = 0 ;j<SIZE && y < 128 ; j++,y++) {
        if ( sch[3] == 1 ){
        image[i][j] = simage1[x][y];
    }//if
    else if ( sch[3] == 2 ){
        image[i][j] = simage2[x][y];
    }//else if
    else if ( sch[3] == 3 ){
        image[i][j] = simage3[x][y];
    }//else if
    else if ( sch[3] == 4 ){
        image[i][j] = simage4[x][y];
    }//else if


        }
  }
}//void
/////////////////////c- blur filter/////////////////////////////////////////
void blur_filter() {
    int bimage[256][256];
    for (int i = 0 ;i<SIZE; i++) {
        for (int j = 0 ;j<SIZE; j++) {

        bimage[i][j] = ((image[i][j])+(image[i][j+1])+(image[i][j+2])+(image[i][j+3])+(image[i][j+4])+(image[i+1][j])+(image[i+1][j+1])+(image[i+1][j+2])+(image[i+1][j+3])+(image[i+1][j+4])+(image[i+2][j])+(image[i+2][j+1])+(image[i+2][j+2])+(image[i+2][j+3])+(image[i+2][j+4])+(image[i+3][j])+(image[i+3][j+1])+(image[i+3][j+2])+(image[i+3][j+3])+(image[i+3][j+4])+(image[i+4][j])+(image[i+4][j+1])+(image[i+4][j+2])+(image[i+4][j+3])+(image[i+4][j+4]))/25;

    }
  }

    for (int i = 0; i < SIZE ; i++) {
    for (int j = 0; j< SIZE ; j++) {
        image[i][j] = bimage[i][j];

    }
  }

}
/////////////////////////end///////////////////////////////////////////////////////////////
