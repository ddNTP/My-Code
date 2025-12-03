from __future__ import annotations

import re
from dataclasses import dataclass
from typing import Callable, Dict, List


ValidationReport = Dict[str, bool]


@dataclass
class Task:
    """任务定义，包含目标说明和验证逻辑。"""

    name: str
    objective: str
    context: str
    requirements: List[str]
    reward_hint: str
    validator: Callable[[str], ValidationReport]

    def validate(self, proposal: str) -> ValidationReport:
        """调用内置验证器评估方案是否满足要求。"""

        return self.validator(proposal)


def _validate_travel_plan(plan: str) -> ValidationReport:
    """简单验证旅行计划是否满足关键要求。"""

    normalized = plan.lower()
    days_found = set(re.findall(r"day\s*(\d+)|第\s*(\d+)\s*天", normalized))
    has_three_days = {"1", "2", "3"}.issubset({d for group in days_found for d in group if d})

    cities_ok = all(
        any(city in normalized for city in (city_cn, city_en))
        for city_cn, city_en in [("北京", "beijing"), ("上海", "shanghai"), ("杭州", "hangzhou")]
    )

    budget_mentions = bool(re.search(r"预算|费用|cost|budget", plan, flags=re.IGNORECASE))
    currency_mentions = bool(re.search(r"(¥|元|rmb|cny|人民币)", plan, flags=re.IGNORECASE))
    budget_ok = budget_mentions and currency_mentions

    transport_ok = bool(re.search(r"交通|train|flight|plane|bus", plan, flags=re.IGNORECASE))

    passed = has_three_days and cities_ok and budget_ok and transport_ok

    return {
        "has_three_days": has_three_days,
        "covers_cities": cities_ok,
        "budget_specified": budget_ok,
        "transport_included": transport_ok,
        "passed": passed,
    }


def travel_task() -> Task:
    """生成旅行计划任务定义。"""

    return Task(
        name="travel_itinerary",
        objective="生成覆盖北京、上海、杭州的3天旅行计划，包含交通与预算。",
        context=(
            "智能体需要给出可执行的行程方案，每天包含城市、交通方式、主要活动和预算估算。"
            "计划可用于 RL 训练时评测模型的规划与约束遵守能力。"
        ),
        requirements=[
            "包含至少3天行程（Day 1/2/3 或 第1天/第2天/第3天）。",
            "行程需覆盖北京、上海、杭州三座城市，可指定顺序。",
            "每天写明交通方式并给出预算估算（含货币单位）。",
        ],
        reward_hint="按天覆盖全部城市并提供预算细节的方案将获得最高奖励。",
        validator=_validate_travel_plan,
    )


def available_tasks() -> List[str]:
    """列出可用任务键名。"""

    return ["travel_itinerary"]


def generate_task(task_name: str) -> Task:
    """根据名称生成任务定义。"""

    if task_name == "travel_itinerary":
        return travel_task()
    raise ValueError(f"未知任务类型: {task_name}")
