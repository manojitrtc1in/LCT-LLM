#include <cstddef>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <stdexcept>


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
const char SizeTypeFormatSpecifier<uint32_t>::specifier[] = "%" PRIu32;

template <>
const char SizeTypeFormatSpecifier<uint64_t>::specifier[] = "%" PRIu64;

const auto& sizeTypeSpecifier = SizeTypeFormatSpecifier<size_t>::specifier;


class Vector2d
{
public:

	Integer x;

	Integer y;


	bool IsInRectangle
		(
			const Vector2d& bottomRightCorner
		)	const;

	template
		<
			class Container2d
		>
	auto GetValueAtPosition
		(
			Container2d& container2d
		)	const
		-> decltype(container2d[0_z][0_z]);

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
		const Vector2d& bottomRightCorner
	)	const
{
	return (0 <= x) && (x < bottomRightCorner.x) && (0 <= y) && (y < bottomRightCorner.y);
}

template
	<
		class Container2d
	>
auto Vector2d::GetValueAtPosition
	(
		Container2d& container2d
	)	const
	-> decltype(container2d[0_z][0_z])
{
	return container2d[x][y];
}

Vector2d Vector2d::Unit() const
{
	return {Signum(x), Signum(y)};
}

Vector2d Vector2d::RotateLeft() const
{
	Vector2d rotatedVector(*this);

	rotatedVector.RotateLeft();

	return rotatedVector;
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
	MutualArrangement FindMutualArrangement
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

MutualArrangement FindMutualArrangement
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

MutualArrangement FindMutualArrangement
	(
		const Rectangle& rectangle1,
		const Rectangle& rectangle2
	)
{
	auto mutualArrangement = [&rectangle1, &rectangle2](Integer Vector2d::* field)
		{
			return FindMutualArrangement
				(
					rectangle1.upperLeftCorner_.*field,
					rectangle1.bottomRightCorner_.*field,
					rectangle2.upperLeftCorner_.*field,
					rectangle2.bottomRightCorner_.*field
				);
		};
	const auto xMutualArrangement = mutualArrangement(&Vector2d::x);
	const auto yMutualArrangement = mutualArrangement(&Vector2d::y);

	if
		(
			(xMutualArrangement == MutualArrangement::Disjoint) ||
			(yMutualArrangement == MutualArrangement::Disjoint)
		)
	{
		return MutualArrangement::Disjoint;
	}
	if
		(
			(xMutualArrangement == MutualArrangement::Equality) &&
			(yMutualArrangement == MutualArrangement::Equality)
		)
	{
		return MutualArrangement::Equality;
	}
	if
		(
			(xMutualArrangement == MutualArrangement::Equality) ||
			(yMutualArrangement == MutualArrangement::Equality)
		)
	{
		if
			(
				(xMutualArrangement == MutualArrangement::Subset) ||
				(yMutualArrangement == MutualArrangement::Subset)
			)
		{
			return MutualArrangement::Subset;
		}
		if
			(
				(xMutualArrangement == MutualArrangement::Superset) ||
				(yMutualArrangement == MutualArrangement::Superset)
			)
		{
			return MutualArrangement::Superset;
		}
	}
	if
		(
			(xMutualArrangement == MutualArrangement::Subset) &&
			(yMutualArrangement == MutualArrangement::Subset)
		)
	{
		return MutualArrangement::Subset;
	}
	if
		(
			(xMutualArrangement == MutualArrangement::Superset) &&
			(yMutualArrangement == MutualArrangement::Superset)
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


struct Lightbulb
{

	size_t garlandIndex{};

	size_t index{};


	Lightbulb() = default;

	Lightbulb
		(
			size_t garlandIndex,
			size_t lightbulbIndex
		);

};


Lightbulb::Lightbulb
	(
		size_t garlandIndex,
		size_t lightbulbIndex
	)
	: garlandIndex{garlandIndex}
	, index{lightbulbIndex}
{
}


struct FieldCell
{

	bool isLightbulb{};

	Lightbulb lightbulb;


	FieldCell() = default;

	FieldCell
		(
			size_t garlandIndex,
			size_t lightbulbIndex
		);

};


using FieldRow = vector<FieldCell>;

using Field = vector<FieldRow>;


FieldCell::FieldCell
	(
		size_t garlandIndex,
		size_t lightbulbIndex
	)
	: isLightbulb{true}
	, lightbulb{garlandIndex, lightbulbIndex}
{
}


struct Garland
{

	Rectangle boundingRectangle;

	vector<Pleasure> partialPleasureSums;


	Garland() = default;

	Garland
		(
			size_t numberOfLightbulbs
		);

};


using Garlands = vector<Garland>;


Garland::Garland
	(
		size_t numberOfLightbulbs
	)
	: partialPleasureSums(numberOfLightbulbs)
{
}


using Flags = vector<bool>;


Garland ReadGarland
	(
		size_t garlandIndex,
		Field& field
	)
{
	size_t numberOfLightbulbs;

	scanf(sizeTypeSpecifier, &numberOfLightbulbs);

	Garland garland(numberOfLightbulbs);
	Pleasure sumPleasure{};

	for (size_t lightbulbIndex = 0_z; lightbulbIndex < numberOfLightbulbs; ++lightbulbIndex)
	{
		Point2d lightbulbPosition;
		Pleasure pleasure;

		lightbulbPosition.Read();
		scanf("%" PRId64, &pleasure);
		lightbulbPosition.GetValueAtPosition(field) = {garlandIndex, lightbulbIndex};
		garland.boundingRectangle.ExtendBoundary(lightbulbPosition);
		sumPleasure += pleasure;
		garland.partialPleasureSums[lightbulbIndex] = sumPleasure;
	}

	return garland;
}

void ReadGarlands
	(
		size_t numberOfGarlands,
		Field& field,
		Garlands& garlands
	)
{
	garlands.resize(numberOfGarlands);
	for (size_t garlandIndex = 0_z; garlandIndex < numberOfGarlands; ++garlandIndex)
	{
		garlands[garlandIndex] = ReadGarland(garlandIndex, field);
	}
}

void ProcessSwitchEvent
	(
		Flags& garlandTurnedOnFlags
	)
{
	size_t switchedGarlandIndex;

	scanf(sizeTypeSpecifier, &switchedGarlandIndex);
	--switchedGarlandIndex;

	auto garlandTurnedOnFlag = garlandTurnedOnFlags[switchedGarlandIndex];

	garlandTurnedOnFlag = !garlandTurnedOnFlag;
}

void ProcessAskEvent
	(
		const Field& field,
		const Garlands& garlands,
		const Flags& garlandTurnedOnFlags
	)
{
	const Point2d fieldSize{static_cast<Integer>(field.size()), static_cast<Integer>(field.front().size())};
	Rectangle area;

	area.Read();

	Pleasure areaPleasure{};
	const auto numberOfGarlands = garlands.size();
	Flags boundaryIntersectingGarlands(numberOfGarlands);

	for (size_t garlandTurnedOnIndex = 0_z; garlandTurnedOnIndex < numberOfGarlands; ++garlandTurnedOnIndex)
	{
		const auto garlandTurnedOnFlag = garlandTurnedOnFlags[garlandTurnedOnIndex];

		if (!garlandTurnedOnFlag)
		{
			continue;
		}

		const auto& garlandTurnedOn = garlands[garlandTurnedOnIndex];
		const auto mutualArrangement = FindMutualArrangement
			(
				garlandTurnedOn.boundingRectangle,
				area
			);

		switch (mutualArrangement)
		{
		case MutualArrangement::Equality:
		case MutualArrangement::Subset:
			areaPleasure += garlandTurnedOn.partialPleasureSums.back();
			break;

		case MutualArrangement::Superset:
		case MutualArrangement::Intersect:
			boundaryIntersectingGarlands[garlandTurnedOnIndex] = true;
			break;
		}
	}

	Flags isFinalPointInsideFlags(numberOfGarlands);
	vector<size_t> lastBoundaryPoints(numberOfGarlands);
	auto checkBoundaryLineSegment =
		[
			&field,
			&garlands,
			&garlandTurnedOnFlags,
			&fieldSize,
			&areaPleasure,
			&boundaryIntersectingGarlands,
			&isFinalPointInsideFlags,
			&lastBoundaryPoints
		]
		(
			const Point2d& beginPoint,
			const Vector2d& direction,
			Integer length
		)
		{
			const auto normal = direction.RotateLeft();
			const auto beginOutsidePoint = beginPoint + normal;

			if (!beginOutsidePoint.IsInRectangle(fieldSize))
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
				const auto& currentCell = currentPoint.GetValueAtPosition(field);
				const auto currentOutsidePoint = currentPoint + normal;
				const auto& currentOutsideCell = currentOutsidePoint.GetValueAtPosition(field);

				if (!currentOutsideCell.isLightbulb || !currentCell.isLightbulb)
				{
					continue;
				}

				const auto& currentLightbulb = currentCell.lightbulb;
				const auto& currentOutsideLightbulb = currentOutsideCell.lightbulb;

				if (currentLightbulb.garlandIndex != currentOutsideLightbulb.garlandIndex)
				{
					continue;
				}

				const auto garlandIndex = currentLightbulb.garlandIndex;

				if (!garlandTurnedOnFlags[garlandIndex])
				{
					continue;
				}

				const auto indexDifference =
					static_cast<Integer>(currentOutsideLightbulb.index) -
					static_cast<Integer>(currentLightbulb.index);

				if (abs(indexDifference) == 1)
				{
					const auto operatingLightbulbIndex =
						indexDifference == 1 ? currentLightbulb.index : currentOutsideLightbulb.index;

					if (operatingLightbulbIndex >= lastBoundaryPoints[garlandIndex])
					{
						isFinalPointInsideFlags[garlandIndex] = (indexDifference == -1);
						lastBoundaryPoints[garlandIndex] = operatingLightbulbIndex;
					}
					areaPleasure += indexDifference * garlands[garlandIndex]
						.partialPleasureSums[operatingLightbulbIndex];
				}
			}
		};

	checkBoundaryLineSegment(area.GetUpperLeftCorner(), {1, 0}, area.GetWidth());
	checkBoundaryLineSegment(area.GetUpperRightCorner(), {0, 1}, area.GetHeight());
	checkBoundaryLineSegment(area.GetBottomRightCorner(), {-1, 0}, area.GetWidth());
	checkBoundaryLineSegment(area.GetBottomLeftCorner(), {0, -1}, area.GetHeight());
	for (size_t garlandIndex = 0_z; garlandIndex < numberOfGarlands; ++garlandIndex)
	{
		if (isFinalPointInsideFlags[garlandIndex])
		{
			areaPleasure += garlands[garlandIndex].partialPleasureSums.back();
		}
	}
	printf("%" PRId64 "\n", areaPleasure);
}

void ProcessEvents
	(
		const Field& field,
		const Garlands& garlands
	)
{
	Flags garlandTurnedOnFlags(garlands.size(), true);
	size_t numberOfEvents;

	scanf(sizeTypeSpecifier, &numberOfEvents);

	char eventKey[10_z];

	for (size_t eventIndex = 0_z; eventIndex < numberOfEvents; ++eventIndex)
	{
		scanf("%s", eventKey);
		if (eventKey[0_z] == 'S')
		{
			ProcessSwitchEvent(garlandTurnedOnFlags);
		}
		else
		{
			ProcessAskEvent(field, garlands, garlandTurnedOnFlags);
		}
	}
}


int main()
try
{
	size_t numberOfGarlands;
	size_t numberOfRows;
	size_t numberOfColumns;

	scanf(sizeTypeSpecifier, &numberOfRows);
	scanf(sizeTypeSpecifier, &numberOfColumns);
	scanf(sizeTypeSpecifier, &numberOfGarlands);

	Field field(numberOfRows, FieldRow(numberOfColumns));
	Garlands garlands;

	ReadGarlands(numberOfGarlands, field, garlands);
	ProcessEvents(field, garlands);
}
catch (const exception& exception)
{
	printf("An error is occured: %s\n", exception.what());
}