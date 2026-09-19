class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        if x2 <= xCenter:
            x = x2
        elif x1 >= xCenter:
            x = x1
        else:
            x = xCenter

        if y2 <= yCenter:
            y = y2
        elif y1 >= yCenter:
            y = y1
        else:
            y = yCenter

        return math.sqrt((x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter)) <= radius