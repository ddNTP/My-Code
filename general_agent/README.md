# general_agent

用于自动化生成任务定义与验证逻辑的轻量工具包，便于在强化学习训练中快速构建评测环境。

## 目录
- `tasks.py`：任务结构体、示例旅行任务以及验证函数。
- `__init__.py`：导出常用接口。

## 快速上手
```python
from general_agent import generate_task

# 获取旅行计划任务定义
travel = generate_task("travel_itinerary")

# 打印约束
for req in travel.requirements:
    print(req)

# 对模型生成的方案进行验证
proposal = """
Day 1: 北京 -> 上海，乘坐高铁，预算 600 元
Day 2: 上海，外滩与博物馆，预算 800 元
Day 3: 上海 -> 杭州，乘坐高铁，预算 500 元
"""
print(travel.validate(proposal))
```
验证结果以字典形式给出，每个键表示一个检查项；`passed=True` 代表方案满足全部规则，可直接用于 RL 奖励函数。
