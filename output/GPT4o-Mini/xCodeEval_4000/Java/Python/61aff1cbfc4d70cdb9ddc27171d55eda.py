import random
import sys
from collections import deque
from math import gcd, inf

MODULO = 1000 * 1000 * 1000 + 7

class C:
    MAX_RND = 10

    def __init__(self):
        self.rnd = random.Random()
        self.file_name = ""
        self.online_judge = not self.file_name

    def solve1(self):
        for _ in range(10):
            need = self.rnd.randint(1, 10000)
            max_time = self.rnd.randint(1, 10000000)
            free_default_time = self.rnd.randint(1, 10)

            first_default_size = self.rnd.randint(1, 100)
            first_default_time = self.rnd.randint(1, 10)
            first_default_cost = self.rnd.randint(1, 10)

            second_default_size = self.rnd.randint(1, 100)
            second_default_time = self.rnd.randint(1, 10)
            second_default_cost = self.rnd.randint(1, 10)

            answer = self.get_answer(need, max_time, free_default_time,
                                     first_default_size, first_default_time, first_default_cost,
                                     second_default_size, second_default_time, second_default_cost)

            brute_answer = self.get_brute_answer(need, max_time, free_default_time,
                                                  first_default_size, first_default_time, first_default_cost,
                                                  second_default_size, second_default_time, second_default_cost)

            if answer[0] != brute_answer[0]:
                print("GOTCHA", file=sys.stderr)
                print(answer, file=sys.stderr)
                print(brute_answer, file=sys.stderr)
                print(need, max_time, first_default_time, file=sys.stderr)
                print(first_default_size, first_default_time, first_default_cost, file=sys.stderr)
                print(second_default_size, second_default_time, second_default_cost, file=sys.stderr)

    def solve(self):
        need = self.read_int()
        max_time = self.read_int()
        free_default_time = self.read_int()

        first_default_size = self.read_int()
        first_default_time = self.read_int()
        first_default_cost = self.read_int()

        second_default_size = self.read_int()
        second_default_time = self.read_int()
        second_default_cost = self.read_int()

        answer = self.get_answer(need, max_time, free_default_time,
                                 first_default_size, first_default_time, first_default_cost,
                                 second_default_size, second_default_time, second_default_cost)

        print(answer[0])

    def get_answer(self, need, max_time, free_default_time,
                   first_default_size, first_default_time, first_default_cost,
                   second_default_size, second_default_time, second_default_cost):
        answer = inf
        first_optimal = 0
        second_optimal = 0

        for first_count in range(need // first_default_size + 1):
            first_size = first_count * first_default_size
            first_time = first_size * first_default_time
            first_cost = first_count * first_default_cost

            if first_size >= need:
                first_size = need
                first_time = first_default_time * first_size

            can_use_time = max_time - first_time
            need_use_size = need - first_size

            if can_use_time >= 0:
                if free_default_time <= second_default_time:
                    free_time = free_default_time * need_use_size
                    if free_time + first_time <= max_time:
                        if answer > first_cost:
                            answer = first_cost
                            first_optimal = first_count
                            second_optimal = 0
                else:
                    lower_side_count = need_use_size // second_default_size
                    lower_second_size = second_default_size * lower_side_count
                    lower_free_size = need_use_size - lower_second_size

                    lower_second_time = lower_second_size * second_default_time
                    lower_free_time = lower_free_size * free_default_time

                    if lower_second_time + lower_free_time <= can_use_time:
                        if answer > first_cost + lower_side_count * second_default_cost:
                            answer = first_cost + lower_side_count * second_default_cost
                            first_optimal = first_count
                            second_optimal = lower_side_count

                    upper_side_count = (need_use_size + second_default_size - 1) // second_default_size
                    upper_second_size = min(need_use_size, second_default_size * upper_side_count)
                    upper_free_size = need_use_size - upper_second_size

                    upper_second_time = upper_second_size * second_default_time
                    upper_free_time = upper_free_size * free_default_time

                    if upper_second_time + upper_free_time <= can_use_time:
                        if answer > first_cost + upper_side_count * second_default_cost:
                            answer = first_cost + upper_side_count * second_default_cost
                            first_optimal = first_count
                            second_optimal = upper_side_count

                        exact_numerator = (need_use_size * free_default_time - can_use_time)
                        exact_denominator = (free_default_time - second_default_time) * second_default_size

                        if exact_denominator > 0:
                            exact_side_count = (exact_numerator + exact_denominator - 1) // exact_denominator
                            if exact_side_count >= 0:
                                exact_second_size = min(need_use_size, second_default_size * exact_side_count)
                                exact_free_size = need_use_size - exact_second_size

                                exact_second_time = exact_second_size * second_default_time
                                exact_free_time = exact_free_size * free_default_time

                                if exact_second_time + exact_free_time <= can_use_time:
                                    if answer > first_cost + exact_side_count * second_default_cost:
                                        answer = first_cost + exact_side_count * second_default_cost
                                        first_optimal = first_count
                                        second_optimal = exact_side_count

        for second_count in range(need // second_default_size + 1):
            second_size = second_count * second_default_size
            second_time = second_size * second_default_time
            second_cost = second_count * second_default_cost

            if second_size >= need:
                second_size = need
                second_time = second_default_time * second_size

            can_use_time = max_time - second_time
            need_use_size = need - second_size

            if can_use_time >= 0:
                if free_default_time <= first_default_time:
                    free_time = free_default_time * need_use_size
                    if free_time + second_time <= max_time:
                        if answer > second_cost:
                            answer = second_cost
                            second_optimal = second_count
                            first_optimal = 0
                else:
                    lower_side_count = need_use_size // first_default_size
                    lower_first_size = first_default_size * lower_side_count
                    lower_free_size = need_use_size - lower_first_size

                    lower_first_time = lower_first_size * first_default_time
                    lower_free_time = lower_free_size * free_default_time

                    if lower_first_time + lower_free_time <= can_use_time:
                        if answer > second_cost + lower_side_count * first_default_cost:
                            answer = second_cost + lower_side_count * first_default_cost
                            second_optimal = second_count
                            first_optimal = lower_side_count

                    upper_side_count = (need_use_size + first_default_size - 1) // first_default_size
                    upper_first_size = min(need_use_size, first_default_size * upper_side_count)
                    upper_free_size = need_use_size - upper_first_size

                    upper_first_time = upper_first_size * first_default_time
                    upper_free_time = upper_free_size * free_default_time

                    if upper_first_time + upper_free_time <= can_use_time:
                        if answer > second_cost + upper_side_count * first_default_cost:
                            answer = second_cost + upper_side_count * first_default_cost
                            second_optimal = second_count
                            first_optimal = upper_side_count

                        exact_numerator = (need_use_size * free_default_time - can_use_time)
                        exact_denominator = (free_default_time - first_default_time) * first_default_size

                        if exact_denominator > 0:
                            exact_side_count = (exact_numerator + exact_denominator - 1) // exact_denominator
                            if exact_side_count >= 0:
                                exact_first_size = min(need_use_size, first_default_size * exact_side_count)
                                exact_free_size = need_use_size - exact_first_size

                                exact_first_time = exact_first_size * first_default_time
                                exact_free_time = exact_free_size * free_default_time

                                if exact_first_time + exact_free_time <= can_use_time:
                                    if answer > second_cost + exact_side_count * first_default_cost:
                                        answer = second_cost + exact_side_count * first_default_cost
                                        second_optimal = second_count
                                        first_optimal = exact_side_count

        if answer == inf:
            answer = -1

        return answer, first_optimal, second_optimal

    def get_brute_answer(self, need, max_time, free_default_time,
                         first_default_size, first_default_time, first_default_cost,
                         second_default_size, second_default_time, second_default_cost):
        answer = inf
        first_optimal = 0
        second_optimal = 0

        for first_count in range(need // first_default_size + 1):
            first_size = min(need, first_count * first_default_size)
            if first_size >= need:
                first_size = need

            first_time = first_size * first_default_time
            first_cost = first_count * first_default_cost

            need_use_size = need - first_size
            for second_count in range(need_use_size // second_default_size + 1):
                second_size = min(need_use_size, second_count * second_default_size)
                if second_size >= need_use_size:
                    second_size = need_use_size

                second_time = second_size * second_default_time
                second_cost = second_count * second_default_cost

                free_size = need_use_size - second_size
                free_time = free_size * free_default_time

                if first_time + second_time + free_time <= max_time:
                    if answer > first_cost + second_cost:
                        answer = first_cost + second_cost
                        first_optimal = first_count
                        second_optimal = second_count

                if second_size >= need_use_size:
                    break

            if first_size >= need:
                break

        if answer == inf:
            answer = -1

        return answer, first_optimal, second_optimal

    def read_int(self):
        return int(sys.stdin.readline().strip())

    def run(self):
        try:
            if self.online_judge:
                self.solve()
            else:
                while True:
                    try:
                        self.solve()
                        print()
                    except (ValueError, EOFError):
                        break
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)

if __name__ == "__main__":
    C().run()
