



const long double EPS = 0.000001;
using std::pair;

struct point {
	long double x, y;
};

struct line {
	long double a, b, c;
};

struct circle {
	point f;
	long double r;
};

bool parallel(line l1, line l2) {
	return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}

point intersection_point(line l1, line l2) {
	point result;
	result.x = -(l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b);
	result.y = -(l1.a * l2.c - l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b);
	return result;
}

int	id0(line l, circle c) {
	long double d = fabs(l.a * c.f.x + l.b * c.f.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
	if (fabs(d - c.r) < EPS) {
		return 1;
	}
	else {
		if (d > c.r) {
			return 0;
		}
		else {
			return 2;
		}
	}
}

pair<point, point> intersection_point(line l, circle c) {
	pair<point, point> result;
	result.first.x = (l.b * l.b * c.f.x - l.a * l.b * c.f.y - l.a * l.c + l.b * sqrt(c.r * c.r * (l.a * l.a + l.b * l.b) - (l.a * c.f.x + l.b * c.f.y + l.c) * (l.a * c.f.x + l.b * c.f.y + l.c))) / (l.a * l.a + l.b * l.b);
	result.first.y = (-l.a * l.b * c.f.x + l.a * l.a * c.f.y - l.b * l.c - l.a * sqrt(c.r * c.r * (l.a * l.a + l.b * l.b) - (l.a * c.f.x + l.b * c.f.y + l.c) * (l.a * c.f.x + l.b * c.f.y + l.c))) / (l.a * l.a + l.b * l.b);
	result.second.x = (l.b * l.b * c.f.x - l.a * l.b * c.f.y - l.a * l.c - l.b * sqrt(c.r * c.r * (l.a * l.a + l.b * l.b) - (l.a * c.f.x + l.b * c.f.y + l.c) * (l.a * c.f.x + l.b * c.f.y + l.c))) / (l.a * l.a + l.b * l.b);
	result.second.y = (-l.a * l.b * c.f.x + l.a * l.a * c.f.y - l.b * l.c + l.a * sqrt(c.r * c.r * (l.a * l.a + l.b * l.b) - (l.a * c.f.x + l.b * c.f.y + l.c) * (l.a * c.f.x + l.b * c.f.y + l.c))) / (l.a * l.a + l.b * l.b);
	return result;
}

int	id0(circle c1, circle c2) {
	long double d = sqrt((c2.f.x - c1.f.x) * (c2.f.x - c1.f.x) + (c2.f.y - c1.f.y) * (c2.f.y - c1.f.y));
	if (fabs(d - fabs(c1.r + c2.r)) < EPS || fabs(d - fabs(c1.r - c2.r)) < EPS) {
		return 1;
	}
	else {
		if (d < fabs(c1.r + c2.r) && d > fabs(c1.r - c2.r)) {
			return 2;
		}
		else {
			return 0;
		}
	}
}

pair<point, point> intersection_point(circle c1, circle c2) {
	long double a = 2.0 * (c2.f.x - c1.f.x), b = 2.0 * (c2.f.y - c1.f.y), c = (c2.r * c2.r - c1.r * c1.r) - (c2.f.x * c2.f.x - c1.f.x * c1.f.x) - (c2.f.y * c2.f.y - c1.f.y * c1.f.y);
	pair<point, point> result;
	result.first.x = ((b * b * c1.f.x - a * b * c1.f.y - a * c + b * sqrt(c1.r * c1.r * (a * a + b * b) - (a * c1.f.x + b * c1.f.y + c) * (a * c1.f.x + b * c1.f.y + c))) / (a * a + b * b) +
		(b * b * c2.f.x - a * b * c2.f.y - a * c + b * sqrt(c2.r * c2.r * (a * a + b * b) - (a * c2.f.x + b * c2.f.y + c) * (a * c2.f.x + b * c2.f.y + c))) / (a * a + b * b)) / 2;
	result.first.y = ((-a * b * c1.f.x + a * a * c1.f.y - b * c - a * sqrt(c1.r * c1.r * (a * a + b * b) - (a * c1.f.x + b * c1.f.y + c) * (a * c1.f.x + b * c1.f.y + c))) / (a * a + b * b) +
		(-a * b * c2.f.x + a * a * c2.f.y - b * c - a * sqrt(c2.r * c2.r * (a * a + b * b) - (a * c2.f.x + b * c2.f.y + c) * (a * c2.f.x + b * c2.f.y + c))) / (a * a + b * b)) / 2;
	result.second.x = ((b * b * c1.f.x - a * b * c1.f.y - a * c - b * sqrt(c1.r * c1.r * (a * a + b * b) - (a * c1.f.x + b * c1.f.y + c) * (a * c1.f.x + b * c1.f.y + c))) / (a * a + b * b) +
		(b * b * c2.f.x - a * b * c2.f.y - a * c - b * sqrt(c2.r * c2.r * (a * a + b * b) - (a * c2.f.x + b * c2.f.y + c) * (a * c2.f.x + b * c2.f.y + c))) / (a * a + b * b)) / 2;
	result.second.y = ((-a * b * c1.f.x + a * a * c1.f.y - b * c + a * sqrt(c1.r * c1.r * (a * a + b * b) - (a * c1.f.x + b * c1.f.y + c) * (a * c1.f.x + b * c1.f.y + c))) / (a * a + b * b) +
		(-a * b * c2.f.x + a * a * c2.f.y - b * c + a * sqrt(c2.r * c2.r * (a * a + b * b) - (a * c2.f.x + b * c2.f.y + c) * (a * c2.f.x + b * c2.f.y + c))) / (a * a + b * b)) / 2;
	return result;
}

int main() {
	int x, y, r;

	std::cin >> x >> y >> r;
	circle c1;
	c1.f.x = 1.0 * x; c1.f.y = 1.0 * y; c1.r = 1.0 * r;

	std::cin >> x >> y >> r;
	circle c2;
	c2.f.x = 1.0 * x; c2.f.y = 1.0 * y; c2.r = 1.0 * r;
	
	std::cin >> x >> y >> r;
	circle c3;
	c3.f.x = 1.0 * x; c3.f.y = 1.0 * y; c3.r = 1.0 * r;

	std::cout.precision(10);
	if (fabs(c1.r - c2.r) < EPS && fabs(c1.r - c3.r) < EPS)  {
		line l4, l5;

		l4.a = 2 * (c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r);
		l4.b = 2 * (c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r);
		l4.c = -((c1.f.x * c1.f.x * c2.r * c2.r - c2.f.x * c2.f.x * c1.r * c1.r) + (c1.f.y * c1.f.y * c2.r * c2.r - c2.f.y * c2.f.y * c1.r * c1.r));

		l5.a = 2 * (c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r);
		l5.b = 2 * (c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r);
		l5.c = -((c1.f.x * c1.f.x * c3.r * c3.r - c3.f.x * c3.f.x * c1.r * c1.r) + (c1.f.y * c1.f.y * c3.r * c3.r - c3.f.y * c3.f.y * c1.r * c1.r));
		
		if (!parallel(l4, l5)) {
			point p = intersection_point(l4, l5);

			std::cout << p.x << " " << p.y;
		}
	}
	else if (fabs(c1.r - c2.r) < EPS) {
		line l4;
		circle c5;

		l4.a = 2 * (c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r);
		l4.b = 2 * (c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r);
		l4.c = -((c1.f.x * c1.f.x * c2.r * c2.r - c2.f.x * c2.f.x * c1.r * c1.r) + (c1.f.y * c1.f.y * c2.r * c2.r - c2.f.y * c2.f.y * c1.r * c1.r));

		c5.f.x = (c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r);
		c5.f.y = (c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r);
		c5.r = sqrt((((c3.f.x * c3.f.x * c1.r * c1.r - c1.f.x * c1.f.x * c3.r * c3.r) + (c3.f.y * c3.f.y * c1.r * c1.r - c1.f.y * c1.f.y * c3.r * c3.r)) / (c3.r * c3.r - c1.r * c1.r) +
			((c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) * ((c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) +
			((c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) * ((c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r))));

		if (id0(l4, c5)) {
			pair<point, point> p = intersection_point(l4, c5);

			double angle1 = c1.r / sqrt((p.first.x - c1.f.x) * (p.first.x - c1.f.x) + (p.first.y - c1.f.y) * (p.first.y - c1.f.y));
			double angle2 = c1.r / sqrt((p.second.x - c1.f.x) * (p.second.x - c1.f.x) + (p.second.y - c1.f.y) * (p.second.y - c1.f.y));

			if (angle1 > angle2) {
				std::cout << p.first.x << " " << p.first.y;
			}
			else {
				std::cout << p.second.x << " " << p.second.y;
			}
		}
	}
	else if (fabs(c2.r - c3.r) < EPS) {
		circle c4, c5;

		c4.f.x = (c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r);
		c4.f.y = (c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r);
		c4.r = sqrt((((c2.f.x * c2.f.x * c1.r * c1.r - c1.f.x * c1.f.x * c2.r * c2.r) + (c2.f.y * c2.f.y * c1.r * c1.r - c1.f.y * c1.f.y * c2.r * c2.r)) / (c2.r * c2.r - c1.r * c1.r) +
			((c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) * ((c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) +
			((c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) * ((c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r))));

		c5.f.x = (c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r);
		c5.f.y = (c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r);
		c5.r = sqrt((((c3.f.x * c3.f.x * c1.r * c1.r - c1.f.x * c1.f.x * c3.r * c3.r) + (c3.f.y * c3.f.y * c1.r * c1.r - c1.f.y * c1.f.y * c3.r * c3.r)) / (c3.r * c3.r - c1.r * c1.r) +
			((c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) * ((c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) +
			((c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) * ((c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r))));

		if (id0(c4, c5)) {
			pair<point, point> p = intersection_point(c4, c5);

			double angle1 = c1.r / sqrt((p.first.x - c1.f.x) * (p.first.x - c1.f.x) + (p.first.y - c1.f.y) * (p.first.y - c1.f.y));
			double angle2 = c1.r / sqrt((p.second.x - c1.f.x) * (p.second.x - c1.f.x) + (p.second.y - c1.f.y) * (p.second.y - c1.f.y));

			if (angle1 > angle2) {
				std::cout << p.first.x << " " << p.first.y;
			}
			else {
				std::cout << p.second.x << " " << p.second.y;
			}
		}
	}
	else if (fabs(c1.r - c3.r) < EPS) {
		line l5;
		circle c4;

		c4.f.x = (c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r);
		c4.f.y = (c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r);
		c4.r = sqrt((((c2.f.x * c2.f.x * c1.r * c1.r - c1.f.x * c1.f.x * c2.r * c2.r) + (c2.f.y * c2.f.y * c1.r * c1.r - c1.f.y * c1.f.y * c2.r * c2.r)) / (c2.r * c2.r - c1.r * c1.r) +
			((c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) * ((c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) +
			((c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) * ((c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r))));

		l5.a = 2 * (c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r);
		l5.b = 2 * (c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r);
		l5.c = -((c1.f.x * c1.f.x * c3.r * c3.r - c3.f.x * c3.f.x * c1.r * c1.r) + (c1.f.y * c1.f.y * c3.r * c3.r - c3.f.y * c3.f.y * c1.r * c1.r));

		if (id0(l5, c4)) {
			pair<point, point> p = intersection_point(l5, c4);

			double angle1 = c1.r / sqrt((p.first.x - c1.f.x) * (p.first.x - c1.f.x) + (p.first.y - c1.f.y) * (p.first.y - c1.f.y));
			double angle2 = c1.r / sqrt((p.second.x - c1.f.x) * (p.second.x - c1.f.x) + (p.second.y - c1.f.y) * (p.second.y - c1.f.y));

			if (angle1 > angle2) {
				std::cout << p.first.x << " " << p.first.y;
			}
			else {
				std::cout << p.second.x << " " << p.second.y;
			}
		}
	}
	else {
		circle c4, c5;
		
		c4.f.x = (c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r);
		c4.f.y = (c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r);
		c4.r = sqrt((((c2.f.x * c2.f.x * c1.r * c1.r - c1.f.x * c1.f.x * c2.r * c2.r) + (c2.f.y * c2.f.y * c1.r * c1.r - c1.f.y * c1.f.y * c2.r * c2.r)) / (c2.r * c2.r - c1.r * c1.r) +
			((c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) * ((c1.f.x * c2.r * c2.r - c2.f.x * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) +
			((c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r)) * ((c1.f.y * c2.r * c2.r - c2.f.y * c1.r * c1.r) / (c2.r * c2.r - c1.r * c1.r))));
		
		c5.f.x = (c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r);
		c5.f.y = (c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r);
		c5.r = sqrt((((c3.f.x * c3.f.x * c1.r * c1.r - c1.f.x * c1.f.x * c3.r * c3.r) + (c3.f.y * c3.f.y * c1.r * c1.r - c1.f.y * c1.f.y * c3.r * c3.r)) / (c3.r * c3.r - c1.r * c1.r) +
			((c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) * ((c1.f.x * c3.r * c3.r - c3.f.x * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) +
			((c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r)) * ((c1.f.y * c3.r * c3.r - c3.f.y * c1.r * c1.r) / (c3.r * c3.r - c1.r * c1.r))));

		if (id0(c4, c5)) {
			pair<point, point> p = intersection_point(c4, c5);

			double angle1 = c1.r / sqrt((p.first.x - c1.f.x) * (p.first.x - c1.f.x) + (p.first.y - c1.f.y) * (p.first.y - c1.f.y));
			double angle2 = c1.r / sqrt((p.second.x - c1.f.x) * (p.second.x - c1.f.x) + (p.second.y - c1.f.y) * (p.second.y - c1.f.y));

			if (angle1 > angle2) {
				std::cout << p.first.x << " " << p.first.y;
			}
			else {
				std::cout << p.second.x << " " << p.second.y;
			}
		}
	}

	return 0;
}