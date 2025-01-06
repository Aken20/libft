import sys
import math
import heapq
# from pydantic import BaseModel

# Grow and multiply your organisms to end up larger than your opponent.

# width: columns in the game grid
# height: rows in the game grid

global my_a
global my_b
global my_c
global my_d

global Target
Target = ""

global SPORES
SPORES = []

P_array = ["A", "B", "C", "D"]

global Tasks
Tasks = []

class Task:
    i = -1
    steps = []

class Point:
    priority = 0
    _id = -7
    x = 1
    y = 1
    i = 1
    printed = False
    target = 10000
    _type = ""
    _dir = "N"
    is_SPORE = False

class Block:
    def __init__(self):
        self.x = 0
        self.y = 0
        self._type = ""
        self.owner = -1
        self.organ_id = -7
        self.organ_dir = ''
        self.organ_parent_id = -7
        self.organ_root_id = -7

    def cp(self, _x, _y, __type, _owner, _organ_id, _organ_dir, _organ_parent_id, _organ_root_id):
        self.x = _x
        self.y = _y
        self._type = __type
        self.owner = _owner
        self.organ_id = _organ_id
        self.organ_dir = _organ_dir
        self.organ_parent_id = _organ_parent_id
        self.organ_root_id = _organ_root_id


width, height = [int(i) for i in input().split()]

def check_enemy_tenticals(game, x, y):
    if x + 1 < width and game[y][x + 1].owner == 0 and game[y][x + 1]._type == "TENTACLE" and game[y][x + 1].organ_dir == "W":
        return False
    if x - 1 > 0 and game[y][x - 1].owner == 0 and game[y][x - 1]._type == "TENTACLE" and game[y][x - 1].organ_dir == "E":
        return False
    if y + 1 < height and game[y + 1][x].owner == 0 and game[y + 1][x]._type == "TENTACLE" and game[y + 1][x].organ_dir == "N":
        return False
    if y - 1 > 0 and game[y - 1][x].owner == 0 and game[y - 1][x]._type == "TENTACLE" and game[y - 1][x].organ_dir == "S":
        return False
    return True

def check_enemy(game, x, y):
    if x + 1 < width and game[y][x + 1].owner == 0:
        return game[y][x + 1].organ_id
    if x - 1 > 0 and game[y][x - 1].owner == 0:
        return game[y][x - 1].organ_id
    if y + 1 < height and game[y + 1][x].owner == 0:
        return game[y + 1][x].organ_id
    if y - 1 > 0 and game[y - 1][x].owner == 0:
        return game[y - 1][x].organ_id
    if x + 2 < width and game[y][x + 2].owner == 0 and game[y][x + 1].owner == -1 and game[y][x + 1]._type != "WALL":
        return game[y][x + 2].organ_id
    if x - 2 > 0 and game[y][x - 2].owner == 0 and game[y][x - 1].owner == -1 and game[y][x - 1]._type != "WALL":
        return game[y][x - 2].organ_id
    if y + 2 < height and game[y + 2][x].owner == 0 and game[y + 1][x].owner == -1 and game[y + 1][x]._type != "WALL":
        return game[y + 2][x].organ_id
    if y - 2 > 0 and game[y - 2][x].owner == 0 and game[y - 1][x].owner == -1 and game[y - 1][x]._type != "WALL":
        return game[y - 2][x].organ_id
    return 10000

def claculate_task(game, x, y, _id, K, root_count, _next):
    pass

def check_protine(game, x, y):
    if x + 1 < width and game[y][x + 1].owner == 1 and game[y][x + 1]._type == "HARVESTER" and game[y][x + 1].organ_dir == "W":
        return False
    if x - 1 >= 0 and game[y][x - 1].owner == 1 and game[y][x - 1]._type == "HARVESTER" and game[y][x - 1].organ_dir == "E":
        return False
    if y + 1 < height and game[y + 1][x].owner == 1 and game[y + 1][x]._type == "HARVESTER" and game[y + 1][x].organ_dir == "N":
        return False
    if y - 1 >= 0 and game[y - 1][x].owner == 1 and game[y - 1][x]._type == "HARVESTER" and game[y - 1][x].organ_dir == "S":
        return False
    return True

def is_valid_move(game, x, y):
    if x < 0 or x >= width or y < 0 or y >= height:
        return False
    if game[y][x]._type == "WALL" or game[y][x].owner != -1:
        return False
    return True

def check_sporing_loc(game, x, y, i, K):
    if i < 2 and i > -2:
        return -1
    if is_valid_move(game ,x, y) and K == False and game[y][x]._type in P_array:
        return -1
    if is_valid_move(game, x + 2, y) and game[y][x + 2]._type in P_array and check_protine(game, x + 2, y):
        return 1
    if is_valid_move(game, x - 2, y) and game[y][x - 2]._type in P_array and check_protine(game, x - 2, y):
        return 1
    if is_valid_move(game, x, y + 2) and game[y + 2][x]._type in P_array and check_protine(game, x, y + 2):
        return 1
    if is_valid_move(game, x, y - 2) and game[y - 2][x]._type in P_array and check_protine(game, x, y - 2):
        return 1
    if is_valid_move(game, x + 1, y + 1) and game[y + 1][x + 1]._type in P_array and check_protine(game, x + 1, y + 1) and (is_valid_move(game, x, y + 1) or is_valid_move(game, x + 1, y)):
        return 1
    if is_valid_move(game, x - 1, y + 1) and game[y + 1][x - 1]._type in P_array and check_protine(game, x - 1, y + 1) and (is_valid_move(game, x, y + 1) or is_valid_move(game, x - 1, y)):
        return 1
    if is_valid_move(game, x - 1, y - 1) and game[y - 1][x - 1]._type in P_array and check_protine(game, x - 1, y - 1) and (is_valid_move(game, x, y - 1) or is_valid_move(game, x - 1, y)):
        return 1
    if is_valid_move(game, x + 1, y - 1) and game[y - 1][x + 1]._type in P_array and check_protine(game, x + 1, y - 1) and (is_valid_move(game, x, y - 1) or is_valid_move(game, x + 1, y)):
        return 1
    return -1

def check_targeted_protine(game ,_type, protine_list):
    for i in protine_list:
        if i._type == _type and check_protine(game, i.x, i.y) == False:
            # print(i.x, i.y, i._type, check_protine(game, i.x, i.y), file=sys.stderr)
            return False
    return True

def fined_target_protine(game, protine_list):
    if check_targeted_protine(game, "A", protine_list):
        return "A"
    if check_targeted_protine(game, "B", protine_list):
        return "B"
    if check_targeted_protine(game, "C", protine_list):
        return "C"
    if check_targeted_protine(game, "D", protine_list):
        return "D"
    return ""

def SPORER(x, y, _id, i, _dir, _next, target):
    global SPORES
    a = Point()
    if target < _next.target:
        _next.priority = 3
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "SPORER"
        _next._dir = _dir
        _next.target = target
        a.x = x
        a.y = y
        a.i = i
        a._dir = _dir
        # print("GROW", _id, x, y, "SPORER", _dir, a.i, file=sys.stderr)
        a.is_SPORE = True
        SPORES.append(a)
        return True, _next
    return False, _next

def check_points(root_count):
    if root_count <= 2 and my_a >= ((2 * root_count) / 2) and my_b >= ((4 * root_count) / 2) and my_c >= ((2 * root_count) / 2) and my_d >= ((4 * root_count) / 2):
        return True
    return False

def check_spaces(game, x, y, _id, _next, K):
    i = 0
    l = 0
    w = width / 2
    h = height / 2
    s_x = -1
    if x <= w:
        while is_valid_move(game, x + i, y):
            i = i + 1
        i = i - 1
        l = i
        while s_x != -1 and is_valid_move(game, x + i, y):
            s_x = check_sporing_loc(game, x + i, y, i, K)
            i = i - 1
        i = i + 1
        if s_x != -1:
            return SPORER(x, y, _id, i, "E", _next, 9000)
        if l > 3:
            return SPORER(x, y, _id, l, "E", _next, 10000 - l)
    i = 0
    if x >= w:
        while is_valid_move(game, x + i, y):
            i = i - 1
        i = i + 1
        l = i
        while s_x != -1 and is_valid_move(game, x + i, y):
            s_x = check_sporing_loc(game, x + i, y, i, K)
            i = i + 1
        i = i - 1
        if s_x != -1:
            return SPORER(x, y, _id, i, "W", _next, 9000)
        if l < -3:
            return SPORER(x, y, _id, l, "W", _next, 10000 + l)
    i = 0
    if y <= h:
        while is_valid_move(game, x, y + i):
            i = i + 1
        i = i - 1
        l = i
        while s_x != -1 and is_valid_move(game, x, y + i):
            s_x = check_sporing_loc(game, x, y + i, i, K)
            i = i - 1
        i = i + 1
        if s_x != -1:
            return SPORER(x, y, _id, i, "S", _next, 9000)
        if l > 3:
            return SPORER(x, y, _id, l, "S", _next, 10000 - l)
    i = 0
    if y >= h:
        while is_valid_move(game, x, y + i):
            i = i - 1
        i = i + 1
        l = i
        while s_x != -1 and is_valid_move(game, x, y + i):
            s_x = check_sporing_loc(game, x + i, y, i, K)
            i = i + 1
        i = i - 1
        if s_x != -1:
            return SPORER(x, y, _id, i, "N", _next, 9000)
        if l < -3:
            return SPORER(x, y, _id, l, "N", _next, 10000 + l)
    return False, _next

def GROW_TENTACLE(game, x, y, _id, _next):
    if x + 1 < width and game[y][x + 1].owner == 0 and game[y][x + 1].organ_id <= _next.target:
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "E"
        _next.target = game[y][x + 1].organ_id
        # print("GROW", _id, x, y, "TENTACLE", "E")
        return True, _next
    if x - 1 >= 0 and game[y][x - 1].owner == 0 and game[y][x - 1].organ_id <= _next.target:
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "W"
        _next.target = game[y][x - 1].organ_id
        # print("GROW", _id, x, y, "TENTACLE", "W")
        return True, _next
    if y + 1 < height and game[y + 1][x].owner == 0 and game[y + 1][x].organ_id <= _next.target:
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "S"
        _next.target = game[y + 1][x].organ_id
        # print("GROW", _id, x, y, "TENTACLE", "S")
        return True, _next
    if y - 1 >= 0 and game[y - 1][x].owner == 0 and game[y - 1][x].organ_id <= _next.target:
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "N"
        _next.target = game[y - 1][x].organ_id
        # print("GROW", _id, x, y, "TENTACLE", "N")
        return True, _next
    if x + 2 < width and game[y][x + 1].owner == -1 and game[y][x + 1]._type != "WALL" and check_enemy(game, x + 1, y) < _next.target:
        _next.target = check_enemy(game, x + 1, y) + 100
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "E"
        # print("GROW", _id, x, y, "TENTACLE", "E")
        return True, _next
    if x - 2 >= 0 and game[y][x - 1].owner == -1 and game[y][x - 1]._type != "WALL" and check_enemy(game, x - 1, y) < _next.target:
        _next.target = check_enemy(game, x - 1, y) + 100
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "W"
        # print("GROW", _id, x, y, "TENTACLE", "W")
        return True, _next
    if y + 2 < height and game[y + 1][x].owner == -1 and game[y + 1][x]._type != "WALL" and check_enemy(game, x, y + 1) < _next.target:
        _next.target = check_enemy(game, x, y + 1) + 100
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "S"
        # print("GROW", _id, x, y, "TENTACLE", "S")
        return True, _next
    if y - 2 >= 0 and game[y - 1][x].owner == -1 and game[y - 1][x]._type != "WALL" and check_enemy(game, x, y - 1) < _next.target:
        _next.target = check_enemy(game, x, y - 1) + 100
        _next.priority = 4
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "N"
        # print("GROW", _id, x, y, "TENTACLE", "N")
        return True, _next
    return False, _next

def get_harvest_target(_type):
    if _type == Target:
        return -1
    if _type == "A":
        return my_a
    if _type == "B":
        return my_b
    if _type == "C":
        return my_c
    if _type == "D":
        return my_d

def GROW_HARVESTER(game, x, y, _id, _next):
    if x + 1 < width and game[y][x + 1]._type in P_array and check_protine(game, x + 1, y):
        if _next._type != "HARVESTER" or get_harvest_target(game[y][x + 1]._type) < _next.target:
            _next.target = get_harvest_target(game[y][x + 1]._type)
            _next.priority = 2
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "HARVESTER"
            _next._dir = "E"
            # print("GROW", _id, x, y, "HARVESTER", "E")
            return True, _next
    if x - 1 >= 0 and game[y][x - 1]._type in P_array and check_protine(game, x - 1, y):
        if _next._type != "HARVESTER" or get_harvest_target(game[y][x - 1]._type) < _next.target:
            _next.target = get_harvest_target(game[y][x - 1]._type)
            _next.priority = 2
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "HARVESTER"
            _next._dir = "W"
            # print("GROW", _id, x, y, "HARVESTER", "W")
            return True, _next
    if y + 1 < height and game[y + 1][x]._type in P_array and check_protine(game, x, y + 1):
        if _next._type != "HARVESTER" or get_harvest_target(game[y + 1][x]._type) < _next.target:
            _next.target = get_harvest_target(game[y + 1][x]._type)
            _next.priority = 2
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "HARVESTER"
            _next._dir = "S"
            # print("GROW", _id, x, y, "HARVESTER", "S")
            return True, _next
    if y - 1 >= 0 and game[y - 1][x]._type in P_array and check_protine(game, x, y - 1):
        if _next._type != "HARVESTER" or get_harvest_target(game[y - 1][x]._type) < _next.target:
            _next.target = get_harvest_target(game[y - 1][x]._type)
            _next.priority = 2
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "HARVESTER"
            _next._dir = "N"
            # print("GROW", _id, x, y, "HARVESTER", "N")
            return True, _next
    return False, _next


def GROW(game, x, y, _id, K, root_count, _next: Point):
    n = False
    # print(y, x, game[y][x]._type, game[y][x].owner, game[y][x].organ_root_id, game[y][x].organ_id, "RC:", root_count, file=sys.stderr)
    # print("GROW", _next._id, _next.x, _next.y, _next._type, _next._dir, _next.priority, file=sys.stderr)
    if game[y][x].owner != -1 or game[y][x]._type == "WALL" or check_enemy_tenticals(game, x, y) == False:
        return False, _next
    if my_b > 0 and my_c > 0 and _next.priority <= 4:
        n, _next = GROW_TENTACLE(game, x, y, _id, _next)
        if n:
            return n, _next
    if game[y][x]._type in P_array and K == False and ((my_a > 0 and game[y][x]._type == "A") or (my_b > 0 and game[y][x]._type == "B") or (my_c > 0 and game[y][x]._type == "C") or (my_d > 0 and game[y][x]._type == "D")):
        return False, _next
    if check_points(root_count) and _next.priority < 3:
        n, _next = check_spaces(game, x, y, _id, _next, K)
        if n:
            print("ssGROW", _next._id, _next.x, _next.y, _next._type, _next._dir, _next.priority, file=sys.stderr)
            return n, _next
    if my_c > 0 and my_d > 0 and _next.priority <= 2:
        n, _next = GROW_HARVESTER(game, x, y, _id, _next)
        if n:
            return n, _next
    if my_a > 0 and _next.priority < 1:
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "BASIC"
        _next._dir = ""
        return True, _next
    elif my_d > 0 and my_b > 0 and _next.priority < 1:
        # print("GROW", _id, x, y, "SPORER", "S")
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "SPORER"
        _next._dir = "N"
        return True, _next
    elif my_d > 0 and my_c > 0 and _next.priority < 1:
        # print("GROW", _id, x, y, "HARVESTER", "S")
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "HARVESTER"
        _next._dir = "N"
        return True, _next
    elif my_b > 0 and my_c > 0 and _next.priority < 1:
        # print("GROW", _id, x, y, "TENTACLE", "S")
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "N"
        return True, _next
    return False, _next

def manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

def find_shortest_path_to_protein(game, protein_list, x, y):
    # Find all organs positions
    start_x = x
    start_y = y
    # Priority queue for A* algorithm
    open_set = []
    # Format: (f_score, x, y), where f_score is priority
    heapq.heappush(open_set, (0, start_x, start_y))
    # Keep track of where we came from
    came_from = {}
    # g_score[x,y] is the cost from start to (x,y)
    g_score = {(start_x, start_y): 0}
    # f_score[x,y] = g_score[x,y] + heuristic(x,y)
    f_score = {(start_x, start_y): 0}
    # Track visited nodes to avoid cycles
    visited = set()
    while open_set:
        _, current_x, current_y = heapq.heappop(open_set)
        current = (current_x, current_y)
        if current in visited:
            continue
        visited.add(current)
        # Check if we've reached a protein source
        for protein in protein_list:
            if protein.x == current_x and protein.y == current_y and protein._type == Target:
                # Reconstruct path
                path = []
                curr = current
                while curr in came_from:
                    path.append((curr[0], curr[1]))
                    # path[-1].x = curr[0]
                    # path[-1].y = curr[1]
                    curr = came_from[curr]
                # Reverse path to get start-to-end
                path = path[::-1]
                print("targaet", path[0][0], path[0][1], file=sys.stderr)
                # get only the first step
                return path[0][0], path[0][1]
            # Check all neighbors
            for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                neighbor_x = current_x + dx
                neighbor_y = current_y + dy
                neighbor = (neighbor_x, neighbor_y)
                if neighbor in visited:
                    continue
                if not (0 <= neighbor_x < width and 0 <= neighbor_y < height):
                    continue
                if game[neighbor_y][neighbor_x]._type == "WALL":
                    continue
                if game[neighbor_y][neighbor_x].owner != -1:
                    continue
                # Distance from start through current to neighbor
                tentative_g_score = g_score[current] + 1
                if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                    # This path is better than any previous one
                    came_from[neighbor] = current
                    g_score[neighbor] = tentative_g_score
                    # Calculate f_score using Manhattan distance heuristic
                    min_distance = float('inf')
                    for protein in protein_list:
                        if protein._type in P_array:
                            dist = manhattan_distance(neighbor_x, neighbor_y, protein.x, protein.y)
                            min_distance = min(min_distance, dist)
                    f_score[neighbor] = g_score[neighbor] + min_distance
                    heapq.heappush(open_set, (f_score[neighbor], neighbor_x, neighbor_y))
    return -1, -1

def iter_next(game, _root_id: int, K, root_count, protine_list, my_organs):
    global my_a
    global my_b
    global my_c
    global my_d
    global Target
    _next = Point()
    n = False
    Target = fined_target_protine(game, protine_list)
    x = -1
    print(Target, file=sys.stderr)
    for organ in my_organs:
        if organ.organ_root_id == _root_id and is_valid_origin(game, organ):
            print(organ.organ_id, organ.x, organ.y, organ.organ_root_id, _root_id, file=sys.stderr)
            x, y = find_shortest_path_to_protein(game, protine_list, organ.x, organ.y)
            print(x, y, file=sys.stderr)
            if x != -1 and _next.priority < 2:
                n, _next = GROW(game, x, y, organ.organ_id, K, root_count, _next)
                if n:
                    if _next.priority < 2:
                        _next.priority = 2
                    print("ben", _next._id, _next.x, _next.y, n, file=sys.stderr)
                else:
                    if is_valid_move(game, organ.x + 1, organ.y):
                        n, _next = GROW(game, organ.x + 1, organ.y, organ.organ_id, K, root_count, _next)
                    if is_valid_move(game, organ.x - 1, organ.y):
                        n, _next = GROW(game, organ.x - 1, organ.y, organ.organ_id, K, root_count, _next)
                    if is_valid_move(game, organ.x, organ.y + 1):
                        n, _next = GROW(game, organ.x, organ.y + 1, organ.organ_id, K, root_count, _next)
                    if is_valid_move(game, organ.x, organ.y - 1):
                        n, _next = GROW(game, organ.x, organ.y - 1, organ.organ_id, K, root_count, _next)
    if _next.priority > 0:
        if _next._type == "BASIC":
            my_a = my_a - 1
        elif _next._type == "HARVESTER":
            my_c = my_c - 1
            my_d = my_d - 1
        elif _next._type == "SPORER":
            my_b = my_b - 1
            my_d = my_d - 1
        elif _next._type == "TENTACLE":
            my_b = my_b - 1
            my_c = my_c - 1
        if _next._id != -7:
            return True, _next
    return False, _next

def is_valid_origin(game, origin):
    if is_valid_move(game, origin.x + 1, origin.y):
        return True
    if is_valid_move(game, origin.x - 1, origin.y):
        return True
    if is_valid_move(game, origin.x, origin.y + 1):
        return True
    if is_valid_move(game, origin.x, origin.y - 1):
        return True
    return False

def next_move(game, r, _root_ids, root_count, protine_list, my_organs):
    print(r, file=sys.stderr)
    if r == 0:
        return
    n_a = []
    n = False
    K = False
    for j in _root_ids:
        if r > 0:
            r = r - 1
            tmp = Point()
            n, tmp = iter_next(game, j, False, root_count, protine_list, my_organs)
            if n:
                print("tmp ", tmp._id, tmp.x, tmp.y, tmp._type, tmp._dir, len(n_a), file=sys.stderr)
                game[tmp.y][tmp.x].cp(tmp.x, tmp.y, tmp._type, 1, -7, tmp._dir, -7, j)
                n_a.append(tmp)
                continue
            n, tmp = iter_next(game, j, True, root_count, protine_list, my_organs)
            if n:
                print("tmp ", tmp._id, tmp.x, tmp.y, tmp._type, tmp._dir, file=sys.stderr)
                game[tmp.y][tmp.x].cp(tmp.x, tmp.y, tmp._type, 1, -7, tmp._dir, -7, j)
                n_a.append(tmp)
                continue
            n_a.append(Point())
    for i in range(len(n_a)):
        if n_a[i]._id != -7 and n_a[i].printed == False:
            print("GROW", n_a[i]._id, n_a[i].x, n_a[i].y, n_a[i]._type, n_a[i]._dir, file=sys.stderr)
            print("GROW", n_a[i]._id, n_a[i].x, n_a[i].y, n_a[i]._type, n_a[i]._dir)
            n_a[i].printed = True
    for i in range(len(n_a)):
        if n_a[i].printed == False:
            print("WAIT", file=sys.stderr)
            print("WAIT")
    return

while True:
    game = [[ Block() for _ in range(width)] for _ in range(height)]
    entity_count = int(input())
    root_count = 0
    protine_list = []
    my_organs = []
    _root_ids = []
    for i in range(entity_count):
        inputs = input().split()
        x = int(inputs[0])
        y = int(inputs[1])  # grid coordinate
        _type = inputs[2]  # WALL, ROOT, BASIC, TENTACLE, HARVESTER, SPORER, A, B, C, D
        owner = int(inputs[3])  # 1 if your organ, 0 if enemy organ, -1 if neither
        organ_id = int(inputs[4])  # id of this entity if it's an organ, 0 otherwise
        organ_dir = inputs[5]  # N,E,S,W or X if not an organ
        organ_parent_id = int(inputs[6])
        organ_root_id = int(inputs[7])
        game[y][x].cp(x, y, _type, owner, organ_id, organ_dir, organ_parent_id, organ_root_id)
        if owner == 1:
            my_organs.append(game[y][x])
        if owner == 1 and _type == "ROOT":
            root_count = root_count + 1
            _root_ids.append(organ_id)
        if _type in P_array:
            protine_list.append(game[y][x])
    # print(_root_ids, file=sys.stderr)
    my_a, my_b, my_c, my_d = [int(i) for i in input().split()]
    opp_a, opp_b, opp_c, opp_d = [int(i) for i in input().split()]
    required_actions_count = int(input())  # your number of organisms, output an action for each one in any order
    for a in SPORES:
        print("ha!", file=sys.stderr)
        if a.is_SPORE:
            print("GROW", game[a.y][a.x].organ_id, a.x, a.y, "SPORER", a._dir, a.i, a.is_SPORE, file=sys.stderr)
            if a._dir in ["S", "N"]:
                print("SPORE", game[a.y][a.x].organ_id, a.x, a.y + a.i)
                required_actions_count = required_actions_count - 1
            else:
                print("SPORE", game[a.y][a.x].organ_id, a.x + a.i, a.y)
                required_actions_count = required_actions_count - 1
            a.is_SPORE = False
    SPORES = []
    next_move(game, required_actions_count, _root_ids, root_count, protine_list, my_organs)