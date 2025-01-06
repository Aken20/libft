import sys
import math
# from pydantic import BaseModel

# Grow and multiply your organisms to end up larger than your opponent.

# width: columns in the game grid
# height: rows in the game grid

global my_a
global my_b
global my_c
global my_d

# _SPORE = False

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
    _dir = ""
    _SPORE = False
    def cp(self, priority, id, x, y, i, printed, target, _type, _dir, _SPORE):
        self.priority = priority
        self._id = id
        self.x = x
        self.y = y
        self.i = i
        self.printed = printed
        self.target = target
        self._type = _type
        self._dir = _dir
        self._SPORE = _SPORE

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

a = Point()

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

def check_enemy_diagonals(game, x, y):
    if x + 1 < width and y + 1 < height and game[y + 1][x + 1].owner == 0:
        if game[y + 1][x].owner == -1 and game[y + 1][x]._type != "WALL":
            return game[y + 1][x + 1].organ_id, "S"
        elif game[y][x + 1].owner == -1 and game[y][x + 1]._type != "WALL":
            return game[y + 1][x + 1].organ_id, "E"
    if x - 1 >= 0 and y - 1 >= 0 and game[y - 1][x - 1].owner == 0:
        if game[y - 1][x].owner == -1 and game[y - 1][x]._type != "WALL":
            return game[y - 1][x - 1].organ_id, "N"
        elif game[y][x - 1].owner == -1 and game[y][x - 1]._type != "WALL":
            return game[y - 1][x - 1].organ_id, "W"
    if x + 1 < width and y - 1 >= 0 and game[y - 1][x + 1].owner == 0:
        if game[y - 1][x].owner == -1 and game[y - 1][x]._type != "WALL":
            return game[y - 1][x + 1].organ_id, "N"
        elif game[y][x + 1].owner == -1 and game[y][x + 1]._type != "WALL":
            return game[y - 1][x + 1].organ_id, "E"
    if x - 1 >= 0 and y + 1 < height and game[y + 1][x - 1].owner == 0:
        if game[y + 1][x].owner == -1 and game[y + 1][x]._type != "WALL":
            return game[y + 1][x - 1].organ_id, "S"
        elif game[y][x - 1].owner == -1 and game[y][x - 1]._type != "WALL":
            return game[y + 1][x - 1].organ_id, "W"
    return -1, ""

def check_enemy(game, x, y):
    if x + 1 < width and game[y][x + 1].owner == 0:
        return game[y][x + 1].organ_id, "E"
    if x - 1 > 0 and game[y][x - 1].owner == 0:
        return game[y][x - 1].organ_id, "W"
    if y + 1 < height and game[y + 1][x].owner == 0:
        return game[y + 1][x].organ_id, "S"
    if y - 1 > 0 and game[y - 1][x].owner == 0:
        return game[y - 1][x].organ_id, "N"
    return -1, ""

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

def SPORER(game, x, y, _id, i, _dir, _next):
    # print("GROW", _id, x, y, "SPORER", _dir)
    _next.priority = 3
    _next.x = x
    _next.y = y
    _next._id = _id
    _next._type = "SPORER"
    _next._dir = _dir
    a.x = x
    a.y = y
    a.i = i
    a._dir = _dir
    a._SPORE = True
    return True, _next

def check_points(root_count):
    if my_a >= (4 * (root_count / 2)) and my_b >= (4 * (root_count / 2)) and my_c >= (4 * (root_count / 2)) and my_d >= (4 * (root_count / 2)):
        return True
    return False

def check_spaces(game, x, y, _id, _next):
    i = 0
    w = width / 2
    h = height / 2
    if x < w:
        while x + i < width - 1 and (game[y][x + i]._type == "" or game[y][x + i]._type in P_array):
            i = i + 1
        i = i - 1
        if i > 3:
            return SPORER(game, x, y, _id, i, "E", _next)
    i = 0
    if x > w:
        while x + i > 0 and (game[y][x + i]._type == "" or game[y][x + i]._type in P_array):
            i = i - 1
        i = i + 1
        if i < -3:
            return SPORER(game, x, y, _id, i, "W", _next)
    i = 0
    if y < h:
        while y + i < height - 1 and (game[y + i][x]._type == "" or game[y + i][x]._type in P_array):
            i = i + 1
        i = i - 1
        if i > 3:
            return SPORER(game, x, y, _id, i, "S", _next)
    i = 0
    if y > h:
        print(y, i, file=sys.stderr)
        while y + i > 0 and (game[y + i][x]._type == "" or game[y + i][x]._type in P_array):
            print(y, i, file=sys.stderr)
            i = i - 1
        i = i + 1
        if i < -3:
            return SPORER(game, x, y, _id, i, "N", _next)
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
    if x + 2 < width and game[y][x + 1].owner == -1 and game[y][x + 1]._type != "WALL":
        e_id , _dir = check_enemy(game, x + 1, y)
        print("enemy: ", x + 1, y, e_id, _dir, file=sys.stderr)
        if e_id != -1 and e_id < _next.target:
            _next.target = e_id + 100
            _next.priority = 4
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "TENTACLE"
            _next._dir = _dir
    if x - 2 >= 0 and game[y][x - 1].owner == -1 and game[y][x - 1]._type != "WALL":
        e_id , _dir = check_enemy(game, x - 1, y)
        print("enemy: ", x - 1, y, e_id, _dir, file=sys.stderr)
        if e_id != -1 and e_id < _next.target:
            _next.target = e_id + 100
            _next.priority = 4
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "TENTACLE"
            _next._dir = _dir
    if y + 2 < height and game[y + 1][x].owner == -1 and game[y + 1][x]._type != "WALL":
        e_id , _dir = check_enemy(game, x, y + 1)
        print("enemy: ", x, y + 1, e_id, _dir, file=sys.stderr)
        if e_id != -1 and e_id < _next.target:
            _next.target = e_id + 100
            _next.priority = 4
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "TENTACLE"
            _next._dir = _dir
    if y - 2 >= 0 and game[y - 1][x].owner == -1 and game[y - 1][x]._type != "WALL":
        e_id , _dir = check_enemy(game, x, y - 1)
        print("enemy: ", x, y - 1, e_id, _dir, file=sys.stderr)
        if e_id != -1 and e_id < _next.target:
            _next.target = e_id + 100
            _next.priority = 4
            _next.x = x
            _next.y = y
            _next._id = _id
            _next._type = "TENTACLE"
            _next._dir = _dir
        # print("GROW", _id, x, y, "TENTACLE", "E")
        return True, _next
    return False, _next


def GROW_HARVESTER(game, x, y, _id, _next):
    if x + 1 < width and game[y][x + 1]._type in P_array and check_protine(game, x + 1, y):
        _next.priority = 2
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "HARVESTER"
        _next._dir = "E"
        # print("GROW", _id, x, y, "HARVESTER", "E")
        return True, _next
    if x - 1 >= 0 and game[y][x - 1]._type in P_array and check_protine(game, x - 1, y):
        _next.priority = 2
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "HARVESTER"
        _next._dir = "W"
        # print("GROW", _id, x, y, "HARVESTER", "W")
        return True, _next
    if y + 1 < height and game[y + 1][x]._type in P_array and check_protine(game, x, y + 1):
        _next.priority = 2
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "HARVESTER"
        _next._dir = "S"
        # print("GROW", _id, x, y, "HARVESTER", "S")
        return True, _next
    if y - 1 >= 0 and game[y - 1][x]._type in P_array and check_protine(game, x, y - 1):
        _next.priority = 2
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "HARVESTER"
        _next._dir = "N"
        # print("GROW", _id, x, y, "HARVESTER", "N")
        return True, _next
    return False, _next


def GROW(game, x, y, _id, K, root_count, _next):
    n = False
    global my_a
    global my_b
    global my_c
    global my_d
    # print(y, x, game[y][x]._type, game[y][x].owner, game[y][x].organ_root_id, game[y][x].organ_id, file=sys.stderr)
    if game[y][x].owner != -1 or game[y][x]._type == "WALL" or check_enemy_tenticals(game, x, y) == False:
        return False, _next
    if my_b > 0 and my_c > 0 and _next.priority <= 4:
        n, _next = GROW_TENTACLE(game, x, y, _id, _next)
        if n:
            my_c = my_c - 1
            my_b = my_b - 1
            return n, _next
    if game[y][x]._type in P_array and K == False and ((my_a > 0 and game[y][x]._type == "A") or (my_b > 0 and game[y][x]._type == "B") or (my_c > 0 and game[y][x]._type == "C") or (my_d > 0 and game[y][x]._type == "D")):
        return False, _next
    if my_c > 0 and my_d > 0 and _next.priority < 2:
        n, _next = GROW_HARVESTER(game, x, y, _id, _next)
        if n:
            my_d = my_d - 1
            my_c = my_c - 1
            return n, _next
    if check_points(root_count) and _next.priority < 3:
        n, _next = check_spaces(game, x, y, _id, _next)
        if n:
            my_b = my_b - 1
            my_d = my_d - 1
            return n, _next
    if my_a > 0 and _next.priority < 1:
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "BASIC"
        _next._dir = ""
        my_a = my_a - 1
        return True, _next
    elif my_d > 0 and my_b > 0 and _next.priority < 1:
        # print("GROW", _id, x, y, "SPORER", "S")
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "SPORER"
        _next._dir = "N"
        my_b = my_b - 1
        my_d = my_d - 1
        return True, _next
    elif my_d > 0 and my_c > 0 and _next.priority < 1:
        # print("GROW", _id, x, y, "HARVESTER", "S")
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "HARVESTER"
        _next._dir = "N"
        my_d = my_d - 1
        my_c = my_c - 1
        return True, _next
    elif my_b > 0 and my_c > 0 and _next.priority < 1:
        # print("GROW", _id, x, y, "TENTACLE", "S")
        _next.priority = 1
        _next.x = x
        _next.y = y
        _next._id = _id
        _next._type = "TENTACLE"
        _next._dir = "N"
        my_c = my_c - 1
        my_b = my_b - 1
        return True, _next
    return False, _next

def updade_root(game, R: int) -> int:
    res = 10000
    for y in range(height):
        for x in range(width):
            if game[y][x]._type == "ROOT" and game[y][x].owner == 1 and game[y][x].organ_id > R:
                if game[y][x].organ_id < res:
                    res = game[y][x].organ_id
    return res

def iter_next(game, _root_id: int, K, root_count):
    _next = Point()
    tmp = Point()
    n = False
    for y in range(height):
        for x in range(width):
            if game[y][x].owner == 1 and game[y][x].organ_root_id == _root_id:
                # tmp = Point()
                if x + 1 < width:
                    n, tmp = GROW(game, x + 1, y, game[y][x].organ_id, K, root_count, _next)
                    # print("next:", _next.priority,"tmp:", tmp.priority, file=sys.stderr)
                    if n and tmp.priority > _next.priority:
                        _next = tmp
                        # print("GROW", _next._id, _next.x, _next.y, _next._type, _next._dir, file=sys.stderr)
                if x - 1 >= 0:
                    n, tmp = GROW(game, x - 1, y, game[y][x].organ_id, K, root_count, _next)
                    if n and tmp.priority > _next.priority:
                        _next = tmp
                if y + 1 < height:
                    n, tmp = GROW(game, x, y + 1, game[y][x].organ_id, K, root_count, _next)
                    if n and tmp.priority > _next.priority:
                        _next = tmp
                if y - 1 >= 0:
                    n, tmp = GROW(game, x, y - 1, game[y][x].organ_id, K, root_count, _next)
                    if n and tmp.priority > _next.priority:
                        _next = tmp
    if _next.priority > 0:
        # print("k: next:", _next.priority,"tmp:", tmp.priority, file=sys.stderr)
        # print("GROW", tmp._id, tmp.x, tmp.y, tmp._type, tmp._dir, file=sys.stderr)
        return True, _next
    return False, _next

def next_move(game, r, _root_id: int, root_count, protine_list):
    n_a = [Point() for _ in range(r)]
    _next = Point()
    n = False
    i = 0
    root_index = 0
    for i in range(r):
        tmp = Point()
        n, tmp = iter_next(game, _root_id, False, root_count)
        print("1: n", n, file=sys.stderr)
        if n:
            game[tmp.y][tmp.x].cp(tmp.x, tmp.y, tmp._type, 1, -7, '', -7, _root_id)
            n_a[i] = tmp
            _root_id = updade_root(game, _root_id)
            continue
        n, tmp = iter_next(game, _root_id, True, root_count)
        print("2: n", n, file=sys.stderr)
        if n:
            game[tmp.y][tmp.x].cp(tmp.x, tmp.y, tmp._type, 1, -7, '', -7, _root_id)
            n_a[i] = tmp
            _root_id = updade_root(game, _root_id)
            continue
    # for i in n_a:
    #     if i._id != -7 and i._type == "TENTACLE" and i.printed == False:
    #         print("GROW", i._id, i.x, i.y, i._type, i._dir)
    #         print("GROW", i._id, i.x, i.y, i._type, i._dir, file=sys.stderr)
    #         i.printed = True
    # for i in n_a:
    #     if i._id != -7 and i._type == "SPORER" and i.printed == False:
    #         print("GROW", i._id, i.x, i.y, i._type, i._dir)
    #         print("GROW", i._id, i.x, i.y, i._type, i._dir, file=sys.stderr)
    #         i.printed = True
    # for i in n_a:
    #     if i._id != -7 and i._type == "HARVESTER" and i.printed == False:
    #         print("GROW", i._id, i.x, i.y, i._type, i._dir)
    #         print("GROW", i._id, i.x, i.y, i._type, i._dir, file=sys.stderr)
    #         i.printed = True
    for i in n_a:
        if i._id != -7 and i.printed == False:
            print("GROW", i._id, i.x, i.y, i._type, i._dir)
            print("GROW", i._id, i.x, i.y, i._type, i._dir, file=sys.stderr)
            i.printed = True
    for i in n_a:
        if i._id == -7:
            print("WAIT")
    return

while True:
    game = [[ Block() for _ in range(width)] for _ in range(height)]
    entity_count = int(input())
    root_count = 0
    protine_list = []
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
        if owner == 1 and _type == "ROOT":
            root_count = root_count + 1
        if _type in P_array:
            protine_list.append(game[y][x])
            
    my_a, my_b, my_c, my_d = [int(i) for i in input().split()]
    opp_a, opp_b, opp_c, opp_d = [int(i) for i in input().split()]
    required_actions_count = int(input())  # your number of organisms, output an action for each one in any order
    if a._SPORE:
            if a._dir in ["S", "N"]:
                print("SPORE", game[a.y][a.x].organ_id, a.x, a.y + a.i)
            else:
                print("SPORE", game[a.y][a.x].organ_id, a.x + a.i, a.y)
            a._SPORE = False
            required_actions_count = required_actions_count - 1
    next_move(game, required_actions_count, updade_root(game, -1), root_count, protine_list)