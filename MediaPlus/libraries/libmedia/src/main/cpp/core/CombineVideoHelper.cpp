////
//// Created by developer on 12/4/17.
////
//
//#include "CombineVideoHelper.h"
//
//BYTE GetAlphaColor(BYTE oriColor, BYTE newColor, float alpha) {
//    return (BYTE) (newColor * alpha + oriColor * (1 - alpha));
//}
//
//CombineVideoHelper::CombineVideoHelper() {
//
//}
//
//CombineVideoHelper::~CombineVideoHelper() {
//    if (waterMarkConfig != nullptr) {
//        delete waterMarkConfig;
//    }
//}
//
//CombineVideoHelper *CombineVideoHelper::Instance() {
//    static CombineVideoHelper combineVideoHelper;
//    return &combineVideoHelper;
//}
//
//
//int CombineVideoHelper::CombineWaterMark(uint8_t *dst, uint8_t *&src) {
//
//
////    timeval startT;
////    timeval endT;
////
////    gettimeofday(&startT, 0);
//
//    BYTE *data = waterMarkConfig->waterByteData;
//
//    int frameWidth = waterMarkConfig->frameWidth;
//    int frameHeight = waterMarkConfig->frameHeight;
//
//    int markWidth = waterMarkConfig->waterWidth;
//    int markHeight = waterMarkConfig->waterHeight;
//
//    int x = waterMarkConfig->x;
//    int y = waterMarkConfig->y;
//
//    int frameYSize = frameWidth * frameHeight;
//    int frameSize = frameWidth * frameHeight * 3 / 2;
//
//
//    for (int w = 0; w < markWidth; w++) {
//        for (int h = 0; h < markHeight; h++) {
//
//            BYTE alpha = data[(h * markWidth + w) * 4 + 1];
//            if (alpha != 0) {
//
//                BYTE R = data[(h * markWidth + w) * 4 + 1];
//                BYTE G = data[(h * markWidth + w) * 4 + 1];
//                BYTE B = data[(h * markWidth + w) * 4 + 1];
//                float alphaPercent = (float) alpha / 255;
//
//                BYTE Y = (BYTE) ((66 * R + 129 * G + 25 * B + 128) >> 8) + 16;
//                BYTE U = (BYTE) ((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128;
//                BYTE V = (BYTE) ((112 * R - 94 * G - 18 * B + 128) >> 8) + 128;
//
//                Y = RGBRound(Y);
//                U = RGBRound(U);
//                V = RGBRound(V);
//
//                int yPosition = (h + y) * frameWidth + w + x;
//                if (frameSize > yPosition) {
//                    BYTE oriY = src[yPosition];
//                    src[yPosition] = GetAlphaColor(oriY, Y, alphaPercent);
//                }
//
//                int uPosition = frameYSize + (h / 2 + y / 2) * frameWidth / 2 + w / 2 + x / 2;
//                if (w % 2 == 0 && h % 2 == 0 && frameSize > uPosition) {
//                    BYTE oriU = src[uPosition];
//                    src[uPosition] = GetAlphaColor(oriU, U, alphaPercent);
//                }
//
//                int vPosition =
//                        frameYSize + frameYSize / 4 + (h / 2 + y / 2) * frameWidth / 2 + w / 2 +
//                        x / 2;
//                if (w % 2 == 0 && h % 2 == 0 && frameSize > vPosition) {
//                    BYTE oriV = src[vPosition];
//                    src[vPosition] = GetAlphaColor(oriV, V, alphaPercent);
//                }
//
//            }
//
//        }
//    }
////    memcpy(dst, src, frameWidth * frameHeight);
////    memcpy(dst, src + (frameWidth * frameHeight), frameWidth * frameHeight / 4);
////    memcpy(dst, src + (frameWidth * frameHeight * 5 / 4), frameWidth * frameHeight / 4);
////    gettimeofday(&endT, 0);
//
////    LOG_D(DEBUG, "water mark host time(ms): %ld", (endT.tv_usec - startT.tv_usec) / 1000);
//    return 0;
//}
//
//void CombineVideoHelper::SetWaterMarkConfig(WaterMarkConfig *&waterMarkConfig) {
//    this->waterMarkConfig = waterMarkConfig;
//    return;
//}