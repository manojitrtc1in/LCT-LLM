#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int32 int
#define uint32 unsigned int32
#define int64 long long
#define uint64 unsigned int64

#define iter(type, var, iterable) for (type::iterator var = (iterable).begin(); var != (iterable).end(); var++)

#define Coordinate int32
#define Pos pair<Coordinate, Coordinate>
#define make_pos make_pair
#define get_x(pos) ((pos).first)
#define get_y(pos) ((pos).second)

#define Quantity uint64
#define Index int32

#define Range pair<Coordinate, Coordinate>
#define make_range make_pair
#define Segment pair<Coordinate, Range>
#define make_segment(coord_1, coord_2_first, coord_2_last) (make_pair((coord_1), make_range(coord_2_first, coord_2_last)))
#define get_coord_1(segment) ((segment).first)
#define get_range(segment) ((segment).second)

#define is_blue_in_red_area(blue_point, red_point) (\
    get_x((blue_point)) <= get_x((red_point)) && get_y((blue_point)) <= get_y((red_point))\
)


#define is_sorted_seq_reversed(sorted_seq) ( get_y((sorted_seq)[0]) > get_y((sorted_seq)[(sorted_seq).size()-1]) )




vector<vector<Pos>> _find_sorted_subseqs(vector<Pos> points_arg) {
    vector<Pos>& points = points_arg;
    sort(points.begin(), points.end());

    vector<vector<Pos>> result_subseqs;

    while (points.size() > 0) {
        Coordinate last_y;

        vector<Pos> best_normal_subseq;
        vector<Index> normal_indices;
        last_y = get_y(points[0]);
        for (Index i = 0; i < points.size(); i++) {
            Pos point = points[i];
            if (get_y(point) >= last_y) {
                best_normal_subseq.push_back(point);
                normal_indices.push_back(i);
                last_y = get_y(point);
            }
        }

        vector<Pos> best_reversed_subseq;
        vector<Index> reversed_indices;
        last_y = get_y(points[0]);
        for (Index i = 0; i < points.size(); i++) {
            Pos point = points[i];
            if (get_y(point) <= last_y) {
                best_reversed_subseq.push_back(point);
                reversed_indices.push_back(i);
                last_y = get_y(point);
            }
        }

        vector<Pos>& best_subseq = best_normal_subseq;
        vector<Index>& best_subseq_indices = normal_indices;
        if (best_normal_subseq.size() < best_reversed_subseq.size()) {
            best_subseq = best_reversed_subseq;
            best_subseq_indices = reversed_indices;
        }

        result_subseqs.push_back(best_subseq);
        Index indices_index = 0;
        vector<Pos> new_points;
        for (Index i_point = 0; i_point < points.size(); i_point++) {
            if (indices_index == best_subseq_indices.size() || i_point != best_subseq_indices[indices_index]) {
                new_points.push_back(points[i_point]);
            }
            else {
                indices_index++;
            }
        }
        points = new_points;
    }

    return result_subseqs;
}


pair<Index, Index> _find_engaged_reversed_blue_points_borders(vector<Pos>& sorted_blue_points, Pos red_point) {
    Index i_first_fit_y;
    Index min_i = 0;
    Index max_i = sorted_blue_points.size();
    while (min_i != max_i) {
        Index mid_i = (min_i + max_i) / 2;
        

        Pos mid_point = sorted_blue_points[mid_i];
        if (get_y(mid_point) <= get_y(red_point)) {
            max_i = mid_i;
        }
        else {
            min_i = mid_i + 1;
        }
    }
    i_first_fit_y = min_i;

    Index i_last_fit_x;
    min_i = -1;
    max_i = sorted_blue_points.size() - 1;
    while (min_i != max_i) {
        Index mid_i = (min_i + max_i + 2) / 2 - 1 + (min_i + max_i + 2) % 2;
        

        Pos mid_point = sorted_blue_points[mid_i];
        if (get_x(mid_point) <= get_x(red_point)) {
            min_i = mid_i;
        }
        else {
            max_i = mid_i - 1;
        }
    }
    i_last_fit_x = min_i;

    return make_pair(i_first_fit_y, i_last_fit_x);
}


Quantity _how_many_sorted_blue_points_fit(vector<Pos>& sorted_blue_points, Pos red_point) {
    if (sorted_blue_points.size() <= 3) {
        Quantity result = 0;
        for (Index i = 0; i < sorted_blue_points.size(); i++) {
            Pos point = sorted_blue_points[i];
            if (get_x(point) <= get_x(red_point) && get_y(point) <= get_y(red_point)) {
                result++;
            }
        }
        return result;
    }

    bool is_reversed = is_sorted_seq_reversed(sorted_blue_points);

    if (!is_reversed) {
        Index min_i = -1;
        Index max_i = sorted_blue_points.size() - 1;
        while (min_i != max_i) {
            Index mid_i = (min_i + max_i + 2) / 2 - 1 + (min_i + max_i + 2) % 2;
            

            Pos mid_point = sorted_blue_points[mid_i];
            if (get_x(mid_point) <= get_x(red_point) && get_y(mid_point) <= get_y(red_point)) {
                min_i = mid_i;
            }
            else {
                max_i = mid_i - 1;
            }
        Quantity result = min_i + 1;
        return result;
        }
    }

    pair<Index, Index> borders = _find_engaged_reversed_blue_points_borders(sorted_blue_points, red_point);
    Index i_first_fit_y = borders.first;
    Index i_last_fit_x = borders.second;

    Quantity result;
    if (i_first_fit_y > i_last_fit_x) {
        result = 0;
    }
    else {
        result = i_last_fit_x - i_first_fit_y + 1;
    }
    return result;
}


Quantity _solve_for_normal_blue_and_normal_red_sorted_points
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Quantity result = 0;
    Index i_blue = 0;
    Quantity blue_accumulated = 0;
    for (Index i_red = 0; i_red < red_points.size(); i_red++) {
        Pos red_point = red_points[i_red];
        while (i_blue < blue_points.size() && is_blue_in_red_area(blue_points[i_blue], red_point)) {
            blue_accumulated++;
            i_blue++;
        }
        result += blue_accumulated;
    }
    return result;
}


Quantity _solve_for_reversed_blue_and_normal_red_sorted_points
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Index i_first_nonzero_red;
    Index min_i = 0;
    Index max_i = red_points.size();
    while (min_i != max_i) {
        Index mid_i = (min_i + max_i) / 2;
        Pos mid_red_point = red_points[mid_i];
        if (_how_many_sorted_blue_points_fit(blue_points, mid_red_point) > 0) {
            max_i = mid_i;
        }
        else {
            min_i = mid_i + 1;
        }
    }
    i_first_nonzero_red = min_i;
    if (i_first_nonzero_red == red_points.size()) {
        return 0;
    }
    Pos first_nonzero_red = red_points[i_first_nonzero_red];
    pair<Index, Index> blue_borders = _find_engaged_reversed_blue_points_borders(blue_points, first_nonzero_red);

    Quantity result = 0;
    Quantity min_blue_per_red = blue_borders.second - blue_borders.first + 1;
    result += min_blue_per_red * (red_points.size() - i_first_nonzero_red);

    Index i_blue;
    Quantity blue_accumulated;

    i_blue = blue_borders.second + 1;
    blue_accumulated = 0;
    for (Index i_red = i_first_nonzero_red; i_red < red_points.size(); i_red++) {
        Pos red_point = red_points[i_red];
        while (i_blue < blue_points.size() && get_x(blue_points[i_blue]) <= get_x(red_point)) {
            blue_accumulated++;
            i_blue++;
        }
        result += blue_accumulated;
    }

    i_blue = blue_borders.first - 1;
    blue_accumulated = 0;
    for (Index i_red = i_first_nonzero_red; i_red < red_points.size(); i_red++) {
        Pos red_point = red_points[i_red];
        while (i_blue >= 0 && get_y(blue_points[i_blue]) <= get_y(red_point)) {
            blue_accumulated++;
            i_blue--;
        }
        result += blue_accumulated;
    }

    return result;
}


Quantity _solve_for_normal_blue_and_reversed_red_sorted_points
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Quantity blue_points_n = blue_points.size();
    vector<Pos> blue_points_as_red_points (blue_points_n);
    for (Index i_blue = 0; i_blue < blue_points_n; i_blue++) {
        Pos point = blue_points[i_blue];
        point = make_pos(-get_x(point), -get_y(point));
        blue_points_as_red_points[blue_points_n-1 - i_blue] = point;
    }

    Quantity red_points_n = red_points.size();
    vector<Pos> red_points_as_blue_points (red_points_n);
    for (Index i_red = 0; i_red < red_points_n; i_red++) {
        Pos point = red_points[i_red];
        point = make_pos(-get_x(point), -get_y(point));
        red_points_as_blue_points[red_points_n-1 - i_red] = point;
    }

    return _solve_for_reversed_blue_and_normal_red_sorted_points(red_points_as_blue_points, blue_points_as_red_points);
}


Quantity _solve_for_reversed_blue_and_reversed_red_sorted_points
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Quantity red_points_n = red_points.size();
    Quantity blue_points_n = blue_points.size();

    Quantity result = 0;

    Index i_blue_active_start = 0;
    Index i_blue_active_stop = 0;
    for (Index i_red = 0; i_red < red_points_n; i_red++) {
        Pos red_point = red_points[i_red];
        while (i_blue_active_stop < blue_points_n
                && get_x(blue_points[i_blue_active_stop]) <= get_x(red_point)) {
            i_blue_active_stop++;
        }
        while (i_blue_active_start < blue_points_n
                && get_y(blue_points[i_blue_active_start]) > get_y(red_point)) {
            i_blue_active_start++;
        }
        if (i_blue_active_start < i_blue_active_stop) {
            result += i_blue_active_stop - i_blue_active_start;
        }
    }

    return result;
}


Quantity _solve_for_blue_and_red_sorted_points(vector<Pos>& blue_points, vector<Pos>& red_points) {
    bool is_blue_seq_reversed = is_sorted_seq_reversed(blue_points);
    bool is_red_seq_reversed = is_sorted_seq_reversed(red_points);

    Quantity result;

    if ((!is_blue_seq_reversed) && (!is_red_seq_reversed)) {
        result = _solve_for_normal_blue_and_normal_red_sorted_points(blue_points, red_points);
    }
    else if ((is_blue_seq_reversed) && (!is_red_seq_reversed)) {
        result = _solve_for_reversed_blue_and_normal_red_sorted_points(blue_points, red_points);
    }
    else if ((!is_blue_seq_reversed) && (is_red_seq_reversed)) {
        result = _solve_for_normal_blue_and_reversed_red_sorted_points(blue_points, red_points);
    }
    else {  

        result = _solve_for_reversed_blue_and_reversed_red_sorted_points(blue_points, red_points);
    }

    return result;
}


vector<Pos> _make_reversed_x(vector<Pos>& points, Pos field_size) {
    vector<Pos> points_reversed_x (points.size());
    for (Index i_point = 0; i_point < points.size(); i_point++) {
        Pos point = points[i_point];
        point = make_pos(get_x(field_size) - get_x(point), get_y(point));
        points_reversed_x[points.size()-1 - i_point] = point;
    }
    return points_reversed_x;
}


vector<Pos> _make_reversed_y(vector<Pos>& points, Pos field_size) {
    vector<Pos> points_reversed_y (points.size());
    for (Index i_point = 0; i_point < points.size(); i_point++) {
        Pos point = points[i_point];
        point = make_pos(get_x(point), get_y(field_size) - get_y(point));
        points_reversed_y[i_point] = point;
    }
    return points_reversed_y;
}


Quantity _solve_for_blue_and_red_subseqs(
    vector<vector<Pos>> blue_points_subseqs, vector<vector<Pos>> red_points_subseqs,
    bool do_reverse_x, bool do_reverse_y, Pos field_size
) {
    if (do_reverse_x) {
        for (Index i_subseq = 0; i_subseq < blue_points_subseqs.size(); i_subseq++) {
            blue_points_subseqs[i_subseq] = _make_reversed_x(blue_points_subseqs[i_subseq], field_size);
        }
        for (Index i_subseq = 0; i_subseq < red_points_subseqs.size(); i_subseq++) {
            red_points_subseqs[i_subseq] = _make_reversed_x(red_points_subseqs[i_subseq], field_size);
        }
    }
    if (do_reverse_y) {
        for (Index i_subseq = 0; i_subseq < blue_points_subseqs.size(); i_subseq++) {
            blue_points_subseqs[i_subseq] = _make_reversed_y(blue_points_subseqs[i_subseq], field_size);
        }
        for (Index i_subseq = 0; i_subseq < red_points_subseqs.size(); i_subseq++) {
            red_points_subseqs[i_subseq] = _make_reversed_y(red_points_subseqs[i_subseq], field_size);
        }
    }

    Quantity result = 0;
    for (Index i_red_subseq = 0; i_red_subseq < red_points_subseqs.size(); i_red_subseq++) {
        for (Index i_blue_subseq = 0; i_blue_subseq < blue_points_subseqs.size(); i_blue_subseq++) {
            result += _solve_for_blue_and_red_sorted_points
                (blue_points_subseqs[i_blue_subseq], red_points_subseqs[i_red_subseq]);
        }
    }
    return result;
}


Quantity how_many_parts_after_dividing
(Pos field_size, vector<Segment>& horizontal_segments, vector<Segment>& vertical_segments) {
    Quantity intersections_n = 0;

    for (Index i = 0; i < horizontal_segments.size(); i++) {
        Range segment_range = get_range(horizontal_segments[i]);
        if (segment_range.first == 0 && segment_range.second == get_x(field_size)) {
            intersections_n++;
        }
    }
    for (Index i = 0; i < vertical_segments.size(); i++) {
        Range segment_range = get_range(vertical_segments[i]);
        if (segment_range.first == 0 && segment_range.second == get_y(field_size)) {
            intersections_n++;
        }
    }

    vector<Pos> blue_points_from_top;
    vector<Pos> blue_points_from_bottom;
    for (Index i_segment = 0; i_segment < vertical_segments.size(); i_segment++) {
        Segment segment = vertical_segments[i_segment];
        Pos blue_point;
        if (get_range(segment).second == get_y(field_size)) {
            Coordinate y = get_range(segment).first;
            blue_point = make_pos(get_coord_1(segment), y);
            blue_points_from_top.push_back(blue_point);
        }
        else {
            Coordinate y = get_range(segment).second;
            blue_point = make_pos(get_coord_1(segment), y);
            blue_points_from_bottom.push_back(blue_point);
        }
    }

    vector<Pos> red_points_from_left;
    vector<Pos> red_points_from_right;
    for (Index i_segment = 0; i_segment < horizontal_segments.size(); i_segment++) {
        Segment segment = horizontal_segments[i_segment];
        Pos red_point;
        if (get_range(segment).first == 0) {
            Coordinate x = get_range(segment).second;
            red_point = make_pos(x, get_coord_1(segment));
            red_points_from_left.push_back(red_point);
        }
        else {
            Coordinate x = get_range(segment).first;
            red_point = make_pos(x, get_coord_1(segment));
            red_points_from_right.push_back(red_point);
        }
    }


    vector<vector<Pos>> blue_points_from_top_subseqs = _find_sorted_subseqs(blue_points_from_top);
    vector<vector<Pos>> blue_points_from_bottom_subseqs = _find_sorted_subseqs(blue_points_from_bottom);
    vector<vector<Pos>> red_points_from_left_subseqs = _find_sorted_subseqs(red_points_from_left);
    vector<vector<Pos>> red_points_from_right_subseqs = _find_sorted_subseqs(red_points_from_right);


    

    intersections_n += _solve_for_blue_and_red_subseqs(
        blue_points_from_top_subseqs, red_points_from_left_subseqs,
        false, false, field_size
    );

    

    intersections_n += _solve_for_blue_and_red_subseqs(
        blue_points_from_top_subseqs, red_points_from_right_subseqs,
        true, false, field_size
    );

    

    intersections_n += _solve_for_blue_and_red_subseqs(
        blue_points_from_bottom_subseqs, red_points_from_left_subseqs,
        false, true, field_size
    );

    

    intersections_n += _solve_for_blue_and_red_subseqs(
        blue_points_from_bottom_subseqs, red_points_from_right_subseqs,
        true, true, field_size
    );

    return 1 + intersections_n;
}


int main() {
    Pos field_size = make_pos(1000000, 1000000);
    Quantity horizontal_n, vertical_n;
    cin >> horizontal_n >> vertical_n;

    vector<Segment> horizontal_segments (horizontal_n);
    for (Index i = 0; i < horizontal_n; i++) {
        Coordinate y, lx, rx;
        cin >> y >> lx >> rx;
        horizontal_segments[i] = make_segment(y, lx, rx);
    }

    vector<Segment> vertical_segments (vertical_n);
    for (Index i = 0; i < vertical_n; i++) {
        Coordinate x, ly, ry;
        cin >> x >> ly >> ry;
        vertical_segments[i] = make_segment(x, ly, ry);
    }

    Quantity result = how_many_parts_after_dividing(field_size, horizontal_segments, vertical_segments);
    cout << result << endl;

    return 0;
}
