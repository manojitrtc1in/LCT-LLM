









using namespace std;


using Integer = int32_t;

using LongInteger = unsigned long long;


constexpr size_t operator "" _z
	(
		LongInteger number
	)
{
	return number <= static_cast<LongInteger>(numeric_limits<size_t>::max())
		? static_cast<size_t>(number)
		: throw domain_error("Invalid argument in 'operator \"\" _z()'.");
}

Integer Signum
	(
		Integer number
	)
{
	return (0 < number) - (0 > number);
}

template
	<
		class SizeType
	>
struct SizeTypeFormatSpecifier
{
	static const char specifier[];
};

template <>
const char SizeTypeFormatSpecifier<uint32_t>::specifier[] = "%" id0;

template <>
const char SizeTypeFormatSpecifier<uint64_t>::specifier[] = "%" id39;

const auto& id31 = SizeTypeFormatSpecifier<size_t>::specifier;


class Vector2d
{
public:

	Integer x;

	Integer y;


	bool IsInRectangle
		(
			const Vector2d& id21
		)	const;

	template
		<
			class Container2d
		>
	auto id27
		(
			Container2d& id22
		)	const
		-> decltype(id22[0_z][0_z]);

	Vector2d Unit() const;

	Vector2d RotateLeft() const;

	void RotateLeft();

	void Read();

	Vector2d& operator +=
		(
			const Vector2d& vector
		);

};


using Point2d = Vector2d;


Vector2d operator +
	(
		const Vector2d& v1,
		const Vector2d& v2
	);

Vector2d operator -
	(
		const Vector2d& v1,
		const Vector2d& v2
	);

bool operator ==
	(
		const Vector2d& v1,
		const Vector2d& v2
	);

bool operator !=
	(
		const Vector2d& v1,
		const Vector2d& v2
	);


bool Vector2d::IsInRectangle
	(
		const Vector2d& id21
	)	const
{
	return (0 <= x) && (x < id21.x) && (0 <= y) && (y < id21.y);
}

template
	<
		class Container2d
	>
auto Vector2d::id27
	(
		Container2d& id22
	)	const
	-> decltype(id22[0_z][0_z])
{
	return id22[x][y];
}

Vector2d Vector2d::Unit() const
{
	return {Signum(x), Signum(y)};
}

Vector2d Vector2d::RotateLeft() const
{
	Vector2d id15(*this);

	id15.RotateLeft();

	return id15;
}

void Vector2d::RotateLeft()
{
	swap(x, y);
	y *= -1;
}

void Vector2d::Read()
{
	scanf("%" PRId32 "%" PRId32, &x, &y);
	--x;
	--y;
}

Vector2d& Vector2d::operator +=
	(
		const Vector2d& vector
	)
{
	x += vector.x;
	y += vector.y;

	return *this;
}

Vector2d operator +
	(
		const Vector2d& v1,
		const Vector2d& v2
	)
{
	return{ v1.x + v2.x, v1.y + v2.y };
}

Vector2d operator -
	(
		const Vector2d& v1,
		const Vector2d& v2
	)
{
	return{ v1.x - v2.x, v1.y - v2.y };
}

bool operator ==
	(
		const Vector2d& v1,
		const Vector2d& v2
	)
{
	return (v1.x == v2.x) && (v1.y == v2.y);
}


bool operator !=
	(
		const Vector2d& v1,
		const Vector2d& v2
	)
{
	return !(v1 == v2);
}


enum class MutualArrangement
{
	Disjoint,
	Intersect,
	Subset,
	Equality,
	Superset
};


class Rectangle
{
public:

	const Vector2d& GetUpperLeftCorner() const;

	Vector2d GetUpperRightCorner() const;

	Vector2d GetBottomLeftCorner() const;

	const Vector2d& GetBottomRightCorner() const;

	Integer GetWidth() const;

	Integer GetHeight() const;

	void ExtendBoundary
		(
			const Point2d& point
		);

	friend
	MutualArrangement id38
		(
			const Rectangle& rectangle1,
			const Rectangle& rectangle2
		);

	void Read();

private:

	Vector2d upperLeftCorner_{numeric_limits<Integer>::max(), numeric_limits<Integer>::max()};

	Vector2d bottomRightCorner_{numeric_limits<Integer>::min(), numeric_limits<Integer>::min()};

};


const Vector2d& Rectangle::GetUpperLeftCorner() const
{
	return upperLeftCorner_;
}

Vector2d Rectangle::GetUpperRightCorner() const
{
	return {bottomRightCorner_.x, upperLeftCorner_.y};
}

Vector2d Rectangle::GetBottomLeftCorner() const
{
	return {upperLeftCorner_.x, bottomRightCorner_.y};
}

const Vector2d& Rectangle::GetBottomRightCorner() const
{
	return bottomRightCorner_;
}

Integer Rectangle::GetWidth() const
{
	return bottomRightCorner_.x - upperLeftCorner_.x + 1;
}

Integer Rectangle::GetHeight() const
{
	return bottomRightCorner_.y - upperLeftCorner_.y + 1;
}


void Rectangle::ExtendBoundary
	(
		const Point2d& point
	)
{
	upperLeftCorner_.x = min(upperLeftCorner_.x, point.x);
	upperLeftCorner_.y = min(upperLeftCorner_.y, point.y);
	bottomRightCorner_.x = max(bottomRightCorner_.x, point.x);
	bottomRightCorner_.y = max(bottomRightCorner_.y, point.y);
}

MutualArrangement id38
	(
		Integer begin1,
		Integer end1,
		Integer begin2,
		Integer end2
	)
{
	if ((begin1 == begin2) && (end2 == end1))
	{
		return MutualArrangement::Equality;
	}
	if ((begin1 <= begin2) && (end2 <= end1))
	{
		return MutualArrangement::Superset;
	}
	if ((begin2 <= begin1) && (end1 <= end2))
	{
		return MutualArrangement::Subset;
	}
	if ((begin1 <= begin2) && (end1 <= end2))
	{
		if (begin2 <= end1)
		{
			return MutualArrangement::Intersect;
		}
		else
		{
			return MutualArrangement::Disjoint;
		}
	}
	else
	{
		if (begin1 <= end2)
		{
			return MutualArrangement::Intersect;
		}
		else
		{
			return MutualArrangement::Disjoint;
		}
	}
}

MutualArrangement id38
	(
		const Rectangle& rectangle1,
		const Rectangle& rectangle2
	)
{
	auto id3 = [&rectangle1, &rectangle2](Integer Vector2d::* field)
		{
			return id38
				(
					rectangle1.upperLeftCorner_.*field,
					rectangle1.bottomRightCorner_.*field,
					rectangle2.upperLeftCorner_.*field,
					rectangle2.bottomRightCorner_.*field
				);
		};
	const auto id24 = id3(&Vector2d::x);
	const auto id25 = id3(&Vector2d::y);

	if
		(
			(id24 == MutualArrangement::Disjoint) ||
			(id25 == MutualArrangement::Disjoint)
		)
	{
		return MutualArrangement::Disjoint;
	}
	if
		(
			(id24 == MutualArrangement::Equality) &&
			(id25 == MutualArrangement::Equality)
		)
	{
		return MutualArrangement::Equality;
	}
	if
		(
			(id24 == MutualArrangement::Equality) ||
			(id25 == MutualArrangement::Equality)
		)
	{
		if
			(
				(id24 == MutualArrangement::Subset) ||
				(id25 == MutualArrangement::Subset)
			)
		{
			return MutualArrangement::Subset;
		}
		if
			(
				(id24 == MutualArrangement::Superset) ||
				(id25 == MutualArrangement::Superset)
			)
		{
			return MutualArrangement::Superset;
		}
	}
	if
		(
			(id24 == MutualArrangement::Subset) &&
			(id25 == MutualArrangement::Subset)
		)
	{
		return MutualArrangement::Subset;
	}
	if
		(
			(id24 == MutualArrangement::Superset) &&
			(id25 == MutualArrangement::Superset)
		)
	{
		return MutualArrangement::Superset;
	}

	return MutualArrangement::Intersect;
}

void Rectangle::Read()
{
	upperLeftCorner_.Read();
	bottomRightCorner_.Read();
}


using Pleasure = int64_t;


struct id40
{

	size_t id1{};

	size_t index{};


	id40() = default;

	id40
		(
			size_t id1,
			size_t id16
		);

};


id40::id40
	(
		size_t id1,
		size_t id16
	)
	: id1{id1}
	, index{id16}
{
}


struct FieldCell
{

	bool isLightbulb{};

	id40 lightbulb;


	FieldCell() = default;

	FieldCell
		(
			size_t id1,
			size_t id16
		);

};


using FieldRow = vector<FieldCell>;

using Field = vector<FieldRow>;


FieldCell::FieldCell
	(
		size_t id1,
		size_t id16
	)
	: isLightbulb{true}
	, lightbulb{id1, id16}
{
}


struct Garland
{

	Rectangle boundingRectangle;

	vector<Pleasure> partialPleasureSums;


	Garland() = default;

	Garland
		(
			size_t id17
		);

};


using Garlands = vector<Garland>;


Garland::Garland
	(
		size_t id17
	)
	: partialPleasureSums(id17)
{
}


using Flags = vector<bool>;


Garland id18
	(
		size_t id1,
		Field& field
	)
{
	size_t id17;

	scanf(id31, &id17);

	Garland garland(id17);
	Pleasure id14{};

	for (size_t id16 = 0_z; id16 < id17; ++id16)
	{
		Point2d id33;
		Pleasure pleasure;

		id33.Read();
		scanf("%" PRId64, &pleasure);
		id33.id27(field) = {id1, id16};
		garland.boundingRectangle.ExtendBoundary(id33);
		id14 += pleasure;
		garland.partialPleasureSums[id16] = id14;
	}

	return garland;
}

void id34
	(
		size_t id37,
		Field& field,
		Garlands& garlands
	)
{
	garlands.resize(id37);
	for (size_t id1 = 0_z; id1 < id37; ++id1)
	{
		garlands[id1] = id18(id1, field);
	}
}

void id13
	(
		Flags& id35
	)
{
	size_t id29;

	scanf(id31, &id29);
	--id29;

	auto id32 = id35[id29];

	id32 = !id32;
}

void id23
	(
		const Field& field,
		const Garlands& garlands,
		const Flags& id35
	)
{
	const Point2d fieldSize{static_cast<Integer>(field.size()), static_cast<Integer>(field.front().size())};
	Rectangle area;

	area.Read();

	Pleasure id20{};
	const auto id37 = garlands.size();
	Flags id2(id37);

	for (size_t id6 = 0_z; id6 < id37; ++id6)
	{
		const auto id32 = id35[id6];

		if (!id32)
		{
			continue;
		}

		const auto& id9 = garlands[id6];
		const auto id3 = id38
			(
				id9.boundingRectangle,
				area
			);

		switch (id3)
		{
		case MutualArrangement::Equality:
		case MutualArrangement::Subset:
			id20 += id9.partialPleasureSums.back();
			break;

		case MutualArrangement::Superset:
		case MutualArrangement::Intersect:
			id2[id6] = true;
			break;
		}
	}

	Flags id30(id37);
	vector<size_t> id4(id37);
	auto id5 =
		[
			&field,
			&garlands,
			&id35,
			&fieldSize,
			&id20,
			&id2,
			&id30,
			&id4
		]
		(
			const Point2d& beginPoint,
			const Vector2d& direction,
			Integer length
		)
		{
			const auto normal = direction.RotateLeft();
			const auto id7 = beginPoint + normal;

			if (!id7.IsInRectangle(fieldSize))
			{
				return;
			}

			Integer currentIndex{};

			for
				(
					auto currentPoint = beginPoint;
					currentIndex < length;
					++currentIndex,
					currentPoint += direction
				)
			{
				const auto& currentCell = currentPoint.id27(field);
				const auto id11 = currentPoint + normal;
				const auto& id26 = id11.id27(field);

				if (!id26.isLightbulb || !currentCell.isLightbulb)
				{
					continue;
				}

				const auto& id19 = currentCell.lightbulb;
				const auto& id8 = id26.lightbulb;

				if (id19.id1 != id8.id1)
				{
					continue;
				}

				const auto id1 = id19.id1;

				if (!id35[id1])
				{
					continue;
				}

				const auto indexDifference =
					static_cast<Integer>(id8.index) -
					static_cast<Integer>(id19.index);

				if (abs(indexDifference) == 1)
				{
					const auto id28 =
						indexDifference == 1 ? id19.index : id8.index;

					if (id28 >= id4[id1])
					{
						id30[id1] = (indexDifference == -1);
						id4[id1] = id28;
					}
					id20 += indexDifference * garlands[id1]
						.partialPleasureSums[id28];
				}
			}
		};

	id5(area.GetUpperLeftCorner(), {1, 0}, area.GetWidth());
	id5(area.GetUpperRightCorner(), {0, 1}, area.GetHeight());
	id5(area.GetBottomRightCorner(), {-1, 0}, area.GetWidth());
	id5(area.GetBottomLeftCorner(), {0, -1}, area.GetHeight());
	for (size_t id1 = 0_z; id1 < id37; ++id1)
	{
		if (id30[id1])
		{
			id20 += garlands[id1].partialPleasureSums.back();
		}
	}
	printf("%" PRId64 "\n", id20);
}

void ProcessEvents
	(
		const Field& field,
		const Garlands& garlands
	)
{
	Flags id35(garlands.size(), true);
	size_t id10;

	scanf(id31, &id10);

	char eventKey[10_z];

	for (size_t eventIndex = 0_z; eventIndex < id10; ++eventIndex)
	{
		scanf("%s", eventKey);
		if (eventKey[0_z] == 'S')
		{
			id13(id35);
		}
		else
		{
			id23(field, garlands, id35);
		}
	}
}


int main()
try
{
	size_t id37;
	size_t id36;
	size_t id12;

	scanf(id31, &id36);
	scanf(id31, &id12);
	scanf(id31, &id37);

	Field field(id36, FieldRow(id12));
	Garlands garlands;

	id34(id37, field, garlands);
	ProcessEvents(field, garlands);
}
catch (const exception& exception)
{
	printf("An error is occured: %s\n", exception.what());
}