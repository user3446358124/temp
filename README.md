## 下载方式
![Snipaste_2023-05-25_16-38-01](https://github.com/user3446358124/temp/assets/116433033/c0542acf-ab2c-4c49-88ab-9ed913afa7e2)
![Snipaste_2023-05-25_16-38-40](https://github.com/user3446358124/temp/assets/116433033/53c4bae3-247c-4d0e-a6b3-d698a7d5277d)


## 说明
1. 上面有个graphics头文件，这个跟exsyx是同源的，不用管
2. 我写的函数主要是直接把它放大到整个窗口界面了
   
3. 你也可以这样做
   1. 先将整个图片手动放大到整个页面
   2. 将loadResource函数替换为
   
` 
void loadResource() 
{

    BeginBatchDraw();
    IMAGE img;
    loadimage(&img, _T("./image/0.jpg"));
    putimage(0, 0, &img);
    FlushBatchDraw();
    EndBatchDraw();
}
`

4. 另外我还改了一下配置，要不直接给你传代码了 :blush:
