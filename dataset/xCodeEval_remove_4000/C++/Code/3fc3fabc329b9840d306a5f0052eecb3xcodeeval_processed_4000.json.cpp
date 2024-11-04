


int main()
{
	char a[60][60];
	char str[110];
	int n, m;
	while (scanf_s("%d%d", &n, &m) != EOF)
	{
		memset(a, '

		for (int i = 1; i <= n; i++) {
			scanf_s("%s", a[i], 110);
		}
		scanf_s("%s", str, 110);
		int sx, sy;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < m; k++) {
				if (a[i][k] == 'S') {
					sx = i; sy = k;
				}
			}
		}
		int nowx = sx, nowy = sy;
		int count = 0, i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx--;
			}
			else if (str[i] == '1') {
				nowx++;
			}
			else if (str[i] == '2') {
				nowy--;
			}
			else if (str[i] == '3') {
				nowy++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx--;
			}
			else if (str[i] == '1') {
				nowx++;
			}
			else if (str[i] == '2') {
				nowy++;
			}
			else if (str[i] == '3') {
				nowy--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx--;
			}
			else if (str[i] == '1') {
				nowy--;
			}
			else if (str[i] == '2') {
				nowx++;
			}
			else if (str[i] == '3') {
				nowy++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx--;
			}
			else if (str[i] == '1') {
				nowy--;
			}
			else if (str[i] == '2') {
				nowy++;
			}
			else if (str[i] == '3') {
				nowx++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx--;
			}
			else if (str[i] == '1') {
				nowy++;
			}
			else if (str[i] == '2') {
				nowy--;
			}
			else if (str[i] == '3') {
				nowx++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx--;
			}
			else if (str[i] == '1') {
				nowy++;
			}
			else if (str[i] == '2') {
				nowx++;
			}
			else if (str[i] == '3') {
				nowy--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}


		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx++;
			}
			else if (str[i] == '1') {
				nowx--;
			}
			else if (str[i] == '2') {
				nowy--;
			}
			else if (str[i] == '3') {
				nowy++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx++;
			}
			else if (str[i] == '1') {
				nowx--;
			}
			else if (str[i] == '2') {
				nowy++;
			}
			else if (str[i] == '3') {
				nowy--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx++;
			}
			else if (str[i] == '1') {
				nowy--;
			}
			else if (str[i] == '2') {
				nowx--;
			}
			else if (str[i] == '3') {
				nowy++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx++;
			}
			else if (str[i] == '1') {
				nowy--;
			}
			else if (str[i] == '2') {
				nowy++;
			}
			else if (str[i] == '3') {
				nowx--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx++;
			}
			else if (str[i] == '1') {
				nowy++;
			}
			else if (str[i] == '2') {
				nowy--;
			}
			else if (str[i] == '3') {
				nowx--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowx++;
			}
			else if (str[i] == '1') {
				nowy++;
			}
			else if (str[i] == '2') {
				nowx--;
			}
			else if (str[i] == '3') {
				nowy--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}


		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy--;
			}
			else if (str[i] == '1') {
				nowx++;
			}
			else if (str[i] == '2') {
				nowx--;
			}
			else if (str[i] == '3') {
				nowy++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy--;
			}
			else if (str[i] == '1') {
				nowx++;
			}
			else if (str[i] == '2') {
				nowy++;
			}
			else if (str[i] == '3') {
				nowx--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy--;
			}
			else if (str[i] == '1') {
				nowx--;
			}
			else if (str[i] == '2') {
				nowx++;
			}
			else if (str[i] == '3') {
				nowy++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy--;
			}
			else if (str[i] == '1') {
				nowx--;
			}
			else if (str[i] == '2') {
				nowy++;
			}
			else if (str[i] == '3') {
				nowx++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy--;
			}
			else if (str[i] == '1') {
				nowy++;
			}
			else if (str[i] == '2') {
				nowx--;
			}
			else if (str[i] == '3') {
				nowx++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy--;
			}
			else if (str[i] == '1') {
				nowy++;
			}
			else if (str[i] == '2') {
				nowx++;
			}
			else if (str[i] == '3') {
				nowx--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}


		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy++;
			}
			else if (str[i] == '1') {
				nowx++;
			}
			else if (str[i] == '2') {
				nowy--;
			}
			else if (str[i] == '3') {
				nowx--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy++;
			}
			else if (str[i] == '1') {
				nowx++;
			}
			else if (str[i] == '2') {
				nowx--;
			}
			else if (str[i] == '3') {
				nowy--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy++;
			}
			else if (str[i] == '1') {
				nowy--;
			}
			else if (str[i] == '2') {
				nowx++;
			}
			else if (str[i] == '3') {
				nowx--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy++;
			}
			else if (str[i] == '1') {
				nowy--;
			}
			else if (str[i] == '2') {
				nowx--;
			}
			else if (str[i] == '3') {
				nowx++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy++;
			}
			else if (str[i] == '1') {
				nowx--;
			}
			else if (str[i] == '2') {
				nowy--;
			}
			else if (str[i] == '3') {
				nowx++;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}
		nowx = sx; nowy = sy; i = 0;
		while (nowy >= 0 && nowy < m&&nowx >= 1 && nowx <= n && a[nowx][nowy] != '

			if (str[i] == '0') {
				nowy++;
			}
			else if (str[i] == '1') {
				nowx--;
			}
			else if (str[i] == '2') {
				nowx++;
			}
			else if (str[i] == '3') {
				nowy--;
			}

			if (a[nowx][nowy] == 'E') {
				count++;
				break;
			}
			i++;
		}

		printf("%d\n", count);
	}
	return 0;
}