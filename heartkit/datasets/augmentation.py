import random

import numpy as np
import numpy.typing as npt


def emg_noise(
    y: npt.NDArray, scale: float = 1e-5, sampling_frequency: int = 1000
) -> npt.NDArray:
    """Add EMG noise to signal

    Args:
        y (npt.NDArray): Signal
        scale (float, optional): Noise scale. Defaults to 1e-5.
        sampling_frequency (int, optional): Sampling rate in Hz. Defaults to 1000.

    Returns:
        npt.NDArray: New signal
    """
    noise = np.repeat(
        np.sin(np.linspace(-0.5 * np.pi, 1.5 * np.pi, sampling_frequency) * 10000),
        np.ceil(y.size / sampling_frequency),
    )
    return y + scale * noise[: y.size]


def lead_noise(y: npt.NDArray, scale: float = 1) -> npt.NDArray:
    """Add Lead noise

    Args:
        y (npt.NDArray): Signal
        scale (float, optional): Noise scale. Defaults to 1.

    Returns:
        npt.NDArray: New signal
    """
    return y + np.random.normal(-scale, scale, size=y.shape)


def random_scaling(
    y: npt.NDArray, lower: float = 0.5, upper: float = 2.0
) -> npt.NDArray:
    """Randomly scale signal.

    Args:
        y (npt.NDArray): Signal
        lower (float, optional): Lower bound. Defaults to 0.5.
        upper (float, optional): Upper bound. Defaults to 2.0.

    Returns:
        npt.NDArray: New signal
    """
    return y * random.uniform(lower, upper)


def baseline_wander(y: npt.NDArray, scale: float = 1e-3) -> npt.NDArray:
    """Apply baseline wander

    Args:
        y (npt.NDArray): Signal
        scale (float, optional): Noise scale. Defaults to 1e-3.

    Returns:
        npt.NDArray: New signal
    """
    skew = np.linspace(0, random.uniform(0, 2) * np.pi, y.size)
    skew = np.sin(skew) * random.uniform(scale / 10, scale)
    y = y + skew
