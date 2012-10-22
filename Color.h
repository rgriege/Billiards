#ifndef COLOR_H
#define COLOR_H

struct Color {
  Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
  Color() : r(0), g(0), b(0) {}
  float r, g, b;
};

const Color kBlack(0, 0, 0);
const Color kRed(1, 0, 0);
const Color kOrange(1, 0.50, 0);
const Color kYellow(1, 1, 0);
const Color kGreen(0, 1, 0);
const Color kIndigo(0, 1, 1);
const Color kBlue(0, 0, 1);
const Color kPurple(0.55, 0, 1);
const Color kWhite(1, 1, 1);
const Color kTan(0.94, 0.90, 0.66);
const Color kBrown(0.42, 0.26, 0.15);
const Color kRainbow[] = {kRed, kOrange, kYellow, kGreen, kIndigo, kBlue,
                          kPurple};
#endif
