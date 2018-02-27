package com.sovworks.eds.android.helpers;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.ClipData;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.BitmapRegionDecoder;
import android.graphics.Rect;
import android.os.Build;
import android.view.WindowManager;

import com.sovworks.eds.fs.Path;

import java.io.IOException;
import java.io.InputStream;

@SuppressLint("NewApi")
public class CompatHelperBase
{
	public static void setWindowFlagSecure(Activity act)
	{
		if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB)
		    act.getWindow().setFlags(WindowManager.LayoutParams.FLAG_SECURE, WindowManager.LayoutParams.FLAG_SECURE);
	}

	public static void restartActivity(Activity activity)
	{
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB)
		    activity.recreate();
		else
		{
		    Intent intent = activity.getIntent();
		    activity.overridePendingTransition(0, 0);
		    intent.addFlags(Intent.FLAG_ACTIVITY_NO_ANIMATION);
		    activity.finish();
		    activity.overridePendingTransition(0, 0);
		    activity.startActivity(intent);
		}
	}

	public static void storeTextInClipboard(Context context,String text)
	{
        if(Build.VERSION.SDK_INT < Build.VERSION_CODES.HONEYCOMB)
        {
            @SuppressWarnings("deprecation") android.text.ClipboardManager clipboard = (android.text.ClipboardManager) context.getSystemService(Context.CLIPBOARD_SERVICE);
            clipboard.setText(text);
        }
        else
        {
            android.content.ClipboardManager clipboard = (android.content.ClipboardManager) context.getSystemService(Context.CLIPBOARD_SERVICE);
            ClipData clip = ClipData.newPlainText("Text", text);
            clipboard.setPrimaryClip(clip);
        }
	}

	public static Bitmap loadBitmapRegion(Path path,int sampleSize,Rect regionRect) throws IOException
	{
		BitmapFactory.Options options = new BitmapFactory.Options();
	    options.inSampleSize = sampleSize;
	    InputStream data = path.getFile().getInputStream();
		try
		{
			if(Build.VERSION.SDK_INT>= Build.VERSION_CODES.GINGERBREAD_MR1)
			{
				BitmapRegionDecoder decoder = BitmapRegionDecoder.newInstance(data, true);
				try
				{
					return decoder.decodeRegion(regionRect, options);
				}
				finally
				{
					decoder.recycle();
				}
			}
			else
				return BitmapFactory.decodeStream(data, null, options);
		}
		finally
		{
			data.close();
		}
	}
		
}
