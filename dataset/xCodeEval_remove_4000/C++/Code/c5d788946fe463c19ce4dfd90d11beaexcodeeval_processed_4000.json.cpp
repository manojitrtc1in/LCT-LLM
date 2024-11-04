


using namespace std;

























    get_x((blue_point)) <= get_x((red_point)) && get_y((blue_point)) <= get_y((red_point))\
)







vector<vector<Pos>> id31(vector<Pos> points_arg) {
    vector<Pos>& points = points_arg;
    sort(points.begin(), points.end());

    vector<vector<Pos>> id13;

    while (points.size() > 0) {
        Coordinate last_y;

        vector<Pos> id47;
        vector<Index> normal_indices;
        last_y = get_y(points[0]);
        for (Index i = 0; i < points.size(); i++) {
            Pos point = points[i];
            if (get_y(point) >= last_y) {
                id47.push_back(point);
                normal_indices.push_back(i);
                last_y = get_y(point);
            }
        }

        vector<Pos> id48;
        vector<Index> id8;
        last_y = get_y(points[0]);
        for (Index i = 0; i < points.size(); i++) {
            Pos point = points[i];
            if (get_y(point) <= last_y) {
                id48.push_back(point);
                id8.push_back(i);
                last_y = get_y(point);
            }
        }

        vector<Pos>& id41 = id47;
        vector<Index>& id35 = normal_indices;
        if (id47.size() < id48.size()) {
            id41 = id48;
            id35 = id8;
        }

        id13.push_back(id41);
        Index indices_index = 0;
        vector<Pos> new_points;
        for (Index i_point = 0; i_point < points.size(); i_point++) {
            if (indices_index == id35.size() || i_point != id35[indices_index]) {
                new_points.push_back(points[i_point]);
            }
            else {
                indices_index++;
            }
        }
        points = new_points;
    }

    return id13;
}


pair<Index, Index> id4(vector<Pos>& id46, Pos red_point) {
    Index id19;
    Index min_i = 0;
    Index max_i = id46.size();
    while (min_i != max_i) {
        Index mid_i = (min_i + max_i) / 2;
        

        Pos mid_point = id46[mid_i];
        if (get_y(mid_point) <= get_y(red_point)) {
            max_i = mid_i;
        }
        else {
            min_i = mid_i + 1;
        }
    }
    id19 = min_i;

    Index id38;
    min_i = -1;
    max_i = id46.size() - 1;
    while (min_i != max_i) {
        Index mid_i = (min_i + max_i + 2) / 2 - 1 + (min_i + max_i + 2) % 2;
        

        Pos mid_point = id46[mid_i];
        if (get_x(mid_point) <= get_x(red_point)) {
            min_i = mid_i;
        }
        else {
            max_i = mid_i - 1;
        }
    }
    id38 = min_i;

    return make_pair(id19, id38);
}


Quantity id37(vector<Pos>& id46, Pos red_point) {
    if (id46.size() <= 3) {
        Quantity result = 0;
        for (Index i = 0; i < id46.size(); i++) {
            Pos point = id46[i];
            if (get_x(point) <= get_x(red_point) && get_y(point) <= get_y(red_point)) {
                result++;
            }
        }
        return result;
    }

    bool id18 = is_sorted_seq_reversed(id46);

    if (!id18) {
        Index min_i = -1;
        Index max_i = id46.size() - 1;
        while (min_i != max_i) {
            Index mid_i = (min_i + max_i + 2) / 2 - 1 + (min_i + max_i + 2) % 2;
            

            Pos mid_point = id46[mid_i];
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

    pair<Index, Index> borders = id4(id46, red_point);
    Index id19 = borders.first;
    Index id38 = borders.second;

    Quantity result;
    if (id19 > id38) {
        result = 0;
    }
    else {
        result = id38 - id19 + 1;
    }
    return result;
}


Quantity id21
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Quantity result = 0;
    Index i_blue = 0;
    Quantity id9 = 0;
    for (Index i_red = 0; i_red < red_points.size(); i_red++) {
        Pos red_point = red_points[i_red];
        while (i_blue < blue_points.size() && is_blue_in_red_area(blue_points[i_blue], red_point)) {
            id9++;
            i_blue++;
        }
        result += id9;
    }
    return result;
}


Quantity id50
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Index id17;
    Index min_i = 0;
    Index max_i = red_points.size();
    while (min_i != max_i) {
        Index mid_i = (min_i + max_i) / 2;
        Pos id52 = red_points[mid_i];
        if (id37(blue_points, id52) > 0) {
            max_i = mid_i;
        }
        else {
            min_i = mid_i + 1;
        }
    }
    id17 = min_i;
    if (id17 == red_points.size()) {
        return 0;
    }
    Pos id0 = red_points[id17];
    pair<Index, Index> id24 = id4(blue_points, id0);

    Quantity result = 0;
    Quantity id26 = id24.second - id24.first + 1;
    result += id26 * (red_points.size() - id17);

    Index i_blue;
    Quantity id9;

    i_blue = id24.second + 1;
    id9 = 0;
    for (Index i_red = id17; i_red < red_points.size(); i_red++) {
        Pos red_point = red_points[i_red];
        while (i_blue < blue_points.size() && get_x(blue_points[i_blue]) <= get_x(red_point)) {
            id9++;
            i_blue++;
        }
        result += id9;
    }

    i_blue = id24.first - 1;
    id9 = 0;
    for (Index i_red = id17; i_red < red_points.size(); i_red++) {
        Pos red_point = red_points[i_red];
        while (i_blue >= 0 && get_y(blue_points[i_blue]) <= get_y(red_point)) {
            id9++;
            i_blue--;
        }
        result += id9;
    }

    return result;
}


Quantity id39
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Quantity id10 = blue_points.size();
    vector<Pos> id44 (id10);
    for (Index i_blue = 0; i_blue < id10; i_blue++) {
        Pos point = blue_points[i_blue];
        point = make_pos(-get_x(point), -get_y(point));
        id44[id10-1 - i_blue] = point;
    }

    Quantity id22 = red_points.size();
    vector<Pos> id43 (id22);
    for (Index i_red = 0; i_red < id22; i_red++) {
        Pos point = red_points[i_red];
        point = make_pos(-get_x(point), -get_y(point));
        id43[id22-1 - i_red] = point;
    }

    return id50(id43, id44);
}


Quantity id53
(vector<Pos>& blue_points, vector<Pos>& red_points) {

    Quantity id22 = red_points.size();
    Quantity id10 = blue_points.size();

    Quantity result = 0;

    Index id3 = 0;
    Index id12 = 0;
    for (Index i_red = 0; i_red < id22; i_red++) {
        Pos red_point = red_points[i_red];
        while (id12 < id10
                && get_x(blue_points[id12]) <= get_x(red_point)) {
            id12++;
        }
        while (id3 < id10
                && get_y(blue_points[id3]) > get_y(red_point)) {
            id3++;
        }
        if (id3 < id12) {
            result += id12 - id3;
        }
    }

    return result;
}


Quantity id16(vector<Pos>& blue_points, vector<Pos>& red_points) {
    bool id36 = is_sorted_seq_reversed(blue_points);
    bool id1 = is_sorted_seq_reversed(red_points);

    Quantity result;

    if ((!id36) && (!id1)) {
        result = id21(blue_points, red_points);
    }
    else if ((id36) && (!id1)) {
        result = id50(blue_points, red_points);
    }
    else if ((!id36) && (id1)) {
        result = id39(blue_points, red_points);
    }
    else {  

        result = id53(blue_points, red_points);
    }

    return result;
}


vector<Pos> id49(vector<Pos>& points, Pos field_size) {
    vector<Pos> id33 (points.size());
    for (Index i_point = 0; i_point < points.size(); i_point++) {
        Pos point = points[i_point];
        point = make_pos(get_x(field_size) - get_x(point), get_y(point));
        id33[points.size()-1 - i_point] = point;
    }
    return id33;
}


vector<Pos> id30(vector<Pos>& points, Pos field_size) {
    vector<Pos> id23 (points.size());
    for (Index i_point = 0; i_point < points.size(); i_point++) {
        Pos point = points[i_point];
        point = make_pos(get_x(point), get_y(field_size) - get_y(point));
        id23[i_point] = point;
    }
    return id23;
}


Quantity id27(
    vector<vector<Pos>> id14, vector<vector<Pos>> id7,
    bool id6, bool id45, Pos field_size
) {
    if (id6) {
        for (Index id40 = 0; id40 < id14.size(); id40++) {
            id14[id40] = id49(id14[id40], field_size);
        }
        for (Index id40 = 0; id40 < id7.size(); id40++) {
            id7[id40] = id49(id7[id40], field_size);
        }
    }
    if (id45) {
        for (Index id40 = 0; id40 < id14.size(); id40++) {
            id14[id40] = id30(id14[id40], field_size);
        }
        for (Index id40 = 0; id40 < id7.size(); id40++) {
            id7[id40] = id30(id7[id40], field_size);
        }
    }

    Quantity result = 0;
    for (Index id32 = 0; id32 < id7.size(); id32++) {
        for (Index id51 = 0; id51 < id14.size(); id51++) {
            result += id16
                (id14[id51], id7[id32]);
        }
    }
    return result;
}


Quantity id29
(Pos field_size, vector<Segment>& horizontal_segments, vector<Segment>& vertical_segments) {
    Quantity id42 = 0;

    for (Index i = 0; i < horizontal_segments.size(); i++) {
        Range segment_range = get_range(horizontal_segments[i]);
        if (segment_range.first == 0 && segment_range.second == get_x(field_size)) {
            id42++;
        }
    }
    for (Index i = 0; i < vertical_segments.size(); i++) {
        Range segment_range = get_range(vertical_segments[i]);
        if (segment_range.first == 0 && segment_range.second == get_y(field_size)) {
            id42++;
        }
    }

    vector<Pos> id2;
    vector<Pos> id28;
    for (Index i_segment = 0; i_segment < vertical_segments.size(); i_segment++) {
        Segment segment = vertical_segments[i_segment];
        Pos blue_point;
        if (get_range(segment).second == get_y(field_size)) {
            Coordinate y = get_range(segment).first;
            blue_point = make_pos(get_coord_1(segment), y);
            id2.push_back(blue_point);
        }
        else {
            Coordinate y = get_range(segment).second;
            blue_point = make_pos(get_coord_1(segment), y);
            id28.push_back(blue_point);
        }
    }

    vector<Pos> id15;
    vector<Pos> id34;
    for (Index i_segment = 0; i_segment < horizontal_segments.size(); i_segment++) {
        Segment segment = horizontal_segments[i_segment];
        Pos red_point;
        if (get_range(segment).first == 0) {
            Coordinate x = get_range(segment).second;
            red_point = make_pos(x, get_coord_1(segment));
            id15.push_back(red_point);
        }
        else {
            Coordinate x = get_range(segment).first;
            red_point = make_pos(x, get_coord_1(segment));
            id34.push_back(red_point);
        }
    }


    vector<vector<Pos>> id25 = id31(id2);
    vector<vector<Pos>> id11 = id31(id28);
    vector<vector<Pos>> id20 = id31(id15);
    vector<vector<Pos>> id5 = id31(id34);


    

    id42 += id27(
        id25, id20,
        false, false, field_size
    );

    

    id42 += id27(
        id25, id5,
        true, false, field_size
    );

    

    id42 += id27(
        id11, id20,
        false, true, field_size
    );

    

    id42 += id27(
        id11, id5,
        true, true, field_size
    );

    return 1 + id42;
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

    Quantity result = id29(field_size, horizontal_segments, vertical_segments);
    cout << result << endl;

    return 0;
}
