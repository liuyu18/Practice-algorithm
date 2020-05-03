class demo:
    def run(self):
        stack = []
        can_match = True
        for item in stack:
            if item == 'm':
                stack.append('m')
            else:
                if len(stack) == 0:
                    can_match = False
                    break
                else:
                    stack.pop()
        if len(stack) > 0:
            can_match = False
        print(can_match)


test = demo()
test.run()


