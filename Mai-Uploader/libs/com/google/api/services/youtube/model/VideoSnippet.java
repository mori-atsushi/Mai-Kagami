// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) ansi 
// Source File Name:   VideoSnippet.java

package com.google.api.services.youtube.model;

import com.google.api.client.json.GenericJson;
import com.google.api.client.util.DateTime;
import com.google.api.client.util.GenericData;
import java.util.List;

// Referenced classes of package com.google.api.services.youtube.model:
//            VideoLocalization, ThumbnailDetails

public final class VideoSnippet extends GenericJson
{

    public VideoSnippet()
    {
    }

    public String getCategoryId()
    {
        return categoryId;
    }

    public VideoSnippet setCategoryId(String s)
    {
        categoryId = s;
        return this;
    }

    public String getChannelId()
    {
        return channelId;
    }

    public VideoSnippet setChannelId(String s)
    {
        channelId = s;
        return this;
    }

    public String getChannelTitle()
    {
        return channelTitle;
    }

    public VideoSnippet setChannelTitle(String s)
    {
        channelTitle = s;
        return this;
    }

    public String getDefaultAudioLanguage()
    {
        return defaultAudioLanguage;
    }

    public VideoSnippet setDefaultAudioLanguage(String s)
    {
        defaultAudioLanguage = s;
        return this;
    }

    public String getDefaultLanguage()
    {
        return defaultLanguage;
    }

    public VideoSnippet setDefaultLanguage(String s)
    {
        defaultLanguage = s;
        return this;
    }

    public String getDescription()
    {
        return description;
    }

    public VideoSnippet setDescription(String s)
    {
        description = s;
        return this;
    }

    public String getLiveBroadcastContent()
    {
        return liveBroadcastContent;
    }

    public VideoSnippet setLiveBroadcastContent(String s)
    {
        liveBroadcastContent = s;
        return this;
    }

    public VideoLocalization getLocalized()
    {
        return localized;
    }

    public VideoSnippet setLocalized(VideoLocalization videolocalization)
    {
        localized = videolocalization;
        return this;
    }

    public DateTime getPublishedAt()
    {
        return publishedAt;
    }

    public VideoSnippet setPublishedAt(DateTime datetime)
    {
        publishedAt = datetime;
        return this;
    }

    public List getTags()
    {
        return tags;
    }

    public VideoSnippet setTags(List list)
    {
        tags = list;
        return this;
    }

    public ThumbnailDetails getThumbnails()
    {
        return thumbnails;
    }

    public VideoSnippet setThumbnails(ThumbnailDetails thumbnaildetails)
    {
        thumbnails = thumbnaildetails;
        return this;
    }

    public String getTitle()
    {
        return title;
    }

    public VideoSnippet setTitle(String s)
    {
        title = s;
        return this;
    }

    public VideoSnippet set(String s, Object obj)
    {
        return (VideoSnippet)super.set(s, obj);
    }

    public VideoSnippet clone()
    {
        return (VideoSnippet)super.clone();
    }

    public volatile GenericJson set(String s, Object obj)
    {
        return set(s, obj);
    }

    public volatile GenericJson clone()
    {
        return clone();
    }

    public volatile GenericData clone()
    {
        return clone();
    }

    public volatile GenericData set(String s, Object obj)
    {
        return set(s, obj);
    }

    public volatile Object clone()
        throws CloneNotSupportedException
    {
        return clone();
    }

    private String categoryId;
    private String channelId;
    private String channelTitle;
    private String defaultAudioLanguage;
    private String defaultLanguage;
    private String description;
    private String liveBroadcastContent;
    private VideoLocalization localized;
    private DateTime publishedAt;
    private List tags;
    private ThumbnailDetails thumbnails;
    private String title;
}
