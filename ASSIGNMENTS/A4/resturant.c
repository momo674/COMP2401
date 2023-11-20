#include "defs.h"

void initRestaurant(RestaurantType *r, char *n) {
    strcpy(r->name, n);
    initResvList(r->reservations);
    initPatronArray(r->patrons);
}

int validateResvTime(int yr, int mth, int day, int hr, int min) {
    if (yr < 2023 || (mth > 12) || (mth < 1) || (day > 31) || (day < 1) || (hr > 24) || (hr < 1) || (min > 60) || (min < 1)) {
        return C_NOK;
    }

    return C_OK;
}

void createResv(RestaurantType *r, int pId, int yr, int mth, int day, int hr, int min) {

}
