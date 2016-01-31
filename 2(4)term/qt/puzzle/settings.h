#ifndef SETTINGS_H
#define SETTINGS_H
#include <QImage>
#include <QPixmap>
#include <string>
class Settings
{
public:
    Settings(std::string filename, int lvl = 0, int p_type = 1);
    QPixmap picture;
    QPixmap masks[ 4 ];
    int n_horiz;
    int n_vert;
    int puzzle_w, puzzle_h;
    int board_w, board_h;

    int part_type;
    int level;
};

#endif // SETTINGS_H
